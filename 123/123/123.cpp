#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#pragma pack(push,1)
typedef struct {
	unsigned short signature;
	unsigned int filesize;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int pixelArrOffset;
} BitmapFileHeader;
typedef struct {
	unsigned int headerSize;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bitsPerPixel;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int xPixelsPerMeter;
	unsigned int yPixelsPerMeter;
	unsigned int colorsInColorTable;
	unsigned int importantColorCount;
} BitmapInfoHeader;
typedef struct {
	unsigned char b;
	unsigned char g;
	unsigned char r;
} Rgb;
#pragma pack(pop)
typedef struct {
	BitmapFileHeader bfh;
	BitmapInfoHeader bih;
	Rgb** arr;
	int error_signal;
	int file_error;
} BMP;
typedef struct {
	char** tval_new;
	char** tval_old;
	int error_flag;
} tokens;
void printInfoHeader(BitmapInfoHeader header) {
	printf("headerSize:\t%x (%u)\n", header.headerSize, header.headerSize);
	printf("width:	 \t%x (%u)\n", header.width, header.width);
	printf("height:	\t%x (%u)\n", header.height, header.height);
	printf("planes:	\t%x (%hu)\n", header.planes, header.planes);
	printf("bitsPerPixel:\t%x (%hu)\n", header.bitsPerPixel, header.bitsPerPixel);
	printf("compression:\t%x (%u)\n", header.compression, header.compression);
	printf("imageSize:\t%x (%u)\n", header.imageSize, header.imageSize);
	printf("xPixelsPerMeter:\t%x (%u)\n", header.xPixelsPerMeter, header.xPixelsPerMeter);
	printf("yPixelsPerMeter:\t%x (%u)\n", header.yPixelsPerMeter, header.yPixelsPerMeter);
	printf("colorsInColorTable:\t%x (%u)\n", header.colorsInColorTable, header.colorsInColorTable);
	printf("importantColorCount:\t%x (%u)\n", header.importantColorCount, header.importantColorCount);
}
void printFileHeader(BitmapFileHeader header) {
	printf("signature:\t%x (%hu)\n", header.signature, header.signature);
	printf("filesize:\t%x (%u)\n", header.filesize, header.filesize);
	printf("reserved1:\t%x (%hu)\n", header.reserved1, header.reserved1);
	printf("reserved2:\t%x (%hu)\n", header.reserved2, header.reserved2);
	printf("pixelArrOffset:\t%x (%u)\n", header.pixelArrOffset, header.pixelArrOffset);
}
void DESCRIPTIONS() {
	printf("\n[DESCRIPTIONS]\n");
	printf("\n	Программа поддерживает интерфейс командной строки и работает только с файлами BMP версии 3");
	printf("\n	Bmp файлы с таблицей цветов не поддерживаются");
	printf("\n	Программа поддерживает только файлы с глубиной 24 пикселя на бит");
	printf("\n	Файл не должен быть сжат\n");
}
void printHelp() {
	printf("\n[FUNCTIONS]\n");
	printf("	(1) - заменить цвет\n");
	printf("	Заменяет все пиксели одного заданного цвета на другой цвет \n");
	printf("	Обязательные аргументы:\n");
	printf("		-o/--oldcolors\n");
	printf("		-n/--newcolors\n");
	printf("\n	(2) - Фильтр rgb-компонент \n");
	printf("	Этот инструмент должен позволять для всего изображения либо установить в 0 либо установить в 255 значение заданной компоненты.\n");
	printf("	Обязательные аргументы:\n");
	printf("		-r/--red\n");
	printf("		-g/--green\n");
	printf("		-b/--blue\n");
	printf("\n	(3) - Разделяет изображение на N*M частей\n");
	printf("	Проводит линии заданной толщины, тем самым разделив изображение\n");
	printf("	Обязательные аргументы:\n");
	printf("		-y/--ylines\n");
	printf("		-x/--xlines\n");
	printf("		-t/--thickness\n");
	printf("		-c/--linecolor\n\n");
	printf("[KEYS]\n");
	printf("		-o/--oldcolors/-n/--newcolors <red>,<green>,<blue>		цвет в формате RGB\n");
	printf("		-r/--red/-g/--green/-b/--blue <value>				устанавливает RGB компонент  <от 0 до 255>\n");
	printf("		-y/--ylines <value>						Количество частей по оси 'Y'+1\n");
	printf("		-x/--xlines <value>						Количество частей по оси 'X'+1\n");
	printf("		-t/--thickness <value>						толщина линии\n");
	printf("		-c/--linecolor <red>,<green>,<blue>				цвет линии\n");
	printf("		-h/-?/--help							справка для пользователя\n");
	printf("		-i/--info							информация об изображении\n");

}
BMP read_image(char* path) {

	BMP image;
	BitmapFileHeader bfh;
	BitmapInfoHeader bih;

	FILE* img = fopen(path, "rb");
	if ((!img) || (!strstr(path, ".bmp"))) {
		image.error_signal = 1;
		return image;
	}
	fread(&bfh, 1, sizeof(BitmapFileHeader), img);
	fread(&bih, 1, sizeof(BitmapInfoHeader), img);
	if (bih.headerSize != 40) {
		printf("FILE ERROR\n");
		image.file_error = 1;
		return image;
	}
	unsigned int H = bih.height;
	unsigned int W = bih.width;

	Rgb** arr = malloc(H * sizeof(Rgb*));
	int offset = (W * sizeof(Rgb)) % 4;
	offset = offset ? 4 - offset : 0;
	for (int i = 0; i < H; i++) {
		arr[i] = malloc(W * sizeof(Rgb) + offset);
		fread(arr[i], 1, W * sizeof(Rgb) + offset, img);
	}

	fclose(img);

	image.bfh = bfh;
	image.bih = bih;
	image.arr = arr;
	image.error_signal = 0;
	return image;
}
void write_image(char* path, BMP data) {
	BitmapFileHeader bfh = data.bfh;
	BitmapInfoHeader bih = data.bih;
	Rgb** arr = data.arr;

	unsigned int H = bih.height;
	unsigned int W = bih.width;

	FILE* f_out = fopen(path, "wb");
	fwrite(&bfh, 1, sizeof(BitmapFileHeader), f_out);
	fwrite(&bih, 1, sizeof(BitmapInfoHeader), f_out);
	int offset = (W * sizeof(Rgb)) % 4;
	offset = offset ? 4 - offset : 0;
	for (int i = 0; i < H; i++) {
		fwrite(arr[i], 1, W * sizeof(Rgb) + offset, f_out);
	}
	fclose(f_out);
}
tokens checking_values(char** argv, int argc) {
	tokens tmp;
	int val_old;
	int val_new;
	char** tval_new = calloc(3, sizeof(char*));
	char** tval_old = calloc(3, sizeof(char*));
	int n = 0;
	int o = 0;
	int ok_N = 1;
	int ok_O = 1;
	char flag[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?/.,|@#$^&*()_+-=;:~`][{}";
	for (int i = 0; i < argc; i++) {
		if (ok_O == 1 && (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--oldcolors"))) {
			ok_O = 0;
			val_old = i + 1;
			char* token = strtok(argv[val_old], ",");
			while (token) {
				tval_old[o] = token;
				if (!(strpbrk(flag, tval_old[o]) == NULL)) {
					printf("\nВведите корректные данные для ключа-o(--oldcolors)\n");
					printf("Используйте ключ --help для вызова справки\n\n");
					tmp.error_flag = 1;
					return tmp;
				}
				o++;
				token = strtok(NULL, ",");
			}
			if (o != 3) {
				tmp.error_flag = 1;
				printf("\nВведите аргумент, где все ТРИ компонента rgb корректны (0 - 255 без пробелов между значениями)\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return tmp;
			}
		}
		if (ok_N == 1 && (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--newcolors"))) {
			ok_N = 0;
			val_new = i + 1;
			char* token = strtok(argv[val_new], ",");
			while (token) {
				tval_new[n] = token;
				if (!(strpbrk(flag, tval_new[n]) == NULL)) {
					printf("\nВведите корректные данные для ключа -n(--newcolors)\n");
					printf("Используйте ключ --help для вызова справки\n\n");
					tmp.error_flag = 1;
					return tmp;
				}
				n++;
				token = strtok(NULL, ",");
			}
			if (n != 3) {
				tmp.error_flag = 1;
				printf("\nВведите аргумент, где все ТРИ компонента rgb корректны (0 - 255 без пробелов между значениями)\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return tmp;
			}
		}
	}
	tmp.tval_new = tval_new;
	tmp.tval_old = tval_old;
	tmp.error_flag = 0;
	return tmp;
}
int color_replacement(tokens tmp, BMP data) {
	char** tval_new = tmp.tval_new;
	char** tval_old = tmp.tval_old;
	if (atoi(tval_old[0]) > 255 || atoi(tval_old[1]) > 255 || atoi(tval_old[2]) > 255 || atoi(tval_new[0]) > 255 || atoi(tval_new[1]) > 255 || atoi(tval_new[2]) > 255) {
		if (atoi(tval_old[0]) < 0 || atoi(tval_old[1]) < 0 || atoi(tval_old[2]) < 0 || atoi(tval_new[0]) < 0 || atoi(tval_new[1]) < 0 || atoi(tval_new[2]) < 0) {
			printf("\nВведите аргумент, где ВСЕ ТРИ компонента rgb корректны (0 - 255 без пробелов между значениями)\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
	}

	Rgb** arr = data.arr;
	unsigned int H = data.bih.height;
	unsigned int W = data.bih.width;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((arr[i][j].r == atoi(tval_old[0])) && (arr[i][j].g == atoi(tval_old[1])) && (arr[i][j].b == atoi(tval_old[2]))) {
				arr[i][j].r = atoi(tval_new[0]);
				arr[i][j].g = atoi(tval_new[1]);
				arr[i][j].b = atoi(tval_new[2]);
			}
		}
	}
	return 1;
}
int filter_rgb_component(char** rgb_value, BMP data) {
	char* component = rgb_value[0];
	char* value = rgb_value[1];

	Rgb** arr = data.arr;
	unsigned int H = data.bih.height;
	unsigned int W = data.bih.width;

	if (strcmp(component, "-r") == 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				arr[i][j].r = atoi(value);
			}
		}
		return 1;
	}
	if (strcmp(component, "-g") == 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				arr[i][j].g = atoi(value);
			}
		}
		return 1;
	}
	if (strcmp(component, "-b") == 0) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				arr[i][j].b = atoi(value);
			}
		}
		return 1;
	}
	printf("\nВведите данные корректно ( -//-.bmp -r 255 -//-.bmp)\n");
	printf("Используйте ключ --help для вызова справки\n");
	return 0;
}
int correct(int x) {
	if (x % 2 == 0) return 1;
	return 0;
}
int cut_on_lines(char** array, BMP data) {
	char flag[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?/.,|@#$^&*()_+-=;:~`][{}";
	char** rgb = calloc(3, sizeof(char*));
	char* token = strtok(array[3], ",");
	int j = 0;
	while (token) {
		rgb[j] = token;
		j++;
		token = strtok(NULL, ",");
	}
	if (j != 3) {
		printf("\nВведите аргумент, где ВСЕ ТРИ компонента rgb корректны (0 - 255 без пробелов между значениями). Например:: -C/--colors value1,value2,value3\n");
		printf("Используйте ключ --help для вызова справки\n\n");
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		if (!(strpbrk(flag, rgb[i]) == NULL)) {
			printf("\nВведите коректные данные для ключа -C(--colors)\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
	}
	Rgb** arr = data.arr;
	unsigned int H = data.bih.height;
	unsigned int W = data.bih.width;
	int N = atoi(array[0]);
	int M = atoi(array[1]);
	int T = atoi(array[2]);

	for (int n = 1; n < N; n++) {
		for (int n1 = ((n * H) / N) - (T / 2 - correct(T)); n1 <= ((n * H) / N) + T / 2; n1++) {
			for (int w1 = 0; w1 <= W; w1++) {
				arr[n1][w1].r = atoi(rgb[0]);
				arr[n1][w1].g = atoi(rgb[1]);
				arr[n1][w1].b = atoi(rgb[2]);
			}
		}
	}
	for (int m = 1; m < M; m++) {
		for (int m1 = ((m * W) / M) - (T / 2 - correct(T)); m1 <= ((m * W) / M) + T / 2; m1++) {
			for (int h1 = 0; h1 < H; h1++) {
				arr[h1][m1].r = atoi(rgb[0]);
				arr[h1][m1].g = atoi(rgb[1]);
				arr[h1][m1].b = atoi(rgb[2]);
			}
		}
	}
}
int b_w_filter(BMP data) {
	Rgb** arr = data.arr;
	unsigned int H = data.bih.height;
	unsigned int W = data.bih.width;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j].r + arr[i][j].b + arr[i][j].g <= (255 * 3 / 2)) {
				arr[i][j].r = 0;
				arr[i][j].g = 0;
				arr[i][j].b = 0;
			}
			else {
				arr[i][j].r = 255;
				arr[i][j].g = 255;
				arr[i][j].b = 255;
			}

		}
	}
	return 1;
}
int comparison(Rgb arr, Rgb tmp) {
	if (arr.r == tmp.r && arr.b == tmp.b && arr.g == tmp.g) {
		return 1;
	}
	return 0;
}
int quantity_color(BMP data) {
	Rgb** arr = data.arr;
	Rgb tmp[sizeof(data.arr) / sizeof(Rgb)];
	tmp[0] = arr[0][0];
	unsigned int H = data.bih.height;
	unsigned int W = data.bih.width;
	int k = 1;
	int count = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 1; j < W; j++) {
			k = count;
			while (k) {
				printf("\n%d", k);
				if (!comparison(arr[i][j], tmp[k])) {
					count++;
					tmp[count] = arr[i][j];
					//printf("\nr=%d,b=%d,g=%d",tmp[count].r,tmp[count].b,tmp[count].g);
				}
				k--;
			}
		}
	}
	return count;
}
int main(int argc, char* argv[]) {

	char* opts = "o:n:r:g:b:y:x:t:c:hifq";

	struct option longOpts[] = {
		{"oldcolors", 1, NULL, 'o'},
		{"newcolors", 1, NULL, 'n'},
		{"red", 1, NULL, 'r'},
		{"green", 1, NULL, 'g'},
		{"blue", 1, NULL, 'b'},
		{"xlines", 1, NULL, 'x'},
		{"ylines", 1, NULL, 'y'},
		{"thickness", 1, NULL, 't'},
		{"linecolor", 1, NULL, 'c'},
		{"help", no_argument, NULL, 'h'},
		{"info", no_argument, NULL, 'i'},
		{"filter", no_argument, NULL, 'f'},
		{"quantity", no_argument, NULL, 'q'},
		{ NULL, 0, NULL, 0}
	};

	int opt;
	int longIndex;
	opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
	char** rgb_value = calloc(2, sizeof(char*));
	char** lines = calloc(4, sizeof(char*));

	char flag[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?/.,|@#$^&*()_+-=;:~`][{}";
	int z11 = 0;
	int z12 = 0;
	int z2 = 0;
	int z30 = 0;
	int z31 = 0;
	int z32 = 0;
	int z33 = 0;
	int inf = 0;
	int zz1 = 0;
	int zz2 = 0;

	while (opt != -1) {
		switch (opt) {
		case 'o':
			z11 = 1;
			break;
		case 'n':
			z12 = 1;
			break;
		case 'r':
			z2 += 1;
			rgb_value[0] = "-r";
			rgb_value[1] = optarg;
			if (!(strpbrk(flag, rgb_value[1]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-r/--red' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}
			break;
		case 'g':
			z2 += 1;
			rgb_value[0] = "-g";
			rgb_value[1] = optarg;
			if (!(strpbrk(flag, rgb_value[1]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-g/--green' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}
			break;
		case 'b':
			z2 += 1;
			rgb_value[0] = "-b";
			rgb_value[1] = optarg;
			if (!(strpbrk(flag, rgb_value[1]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-b/--blue' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}
			break;
		case 'y':
			z30 += 1;
			lines[0] = optarg;
			if (!(strpbrk(flag, lines[0]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-y/--ylines' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}

			break;
		case 'x':
			z31 += 1;
			lines[1] = optarg;
			if (!(strpbrk(flag, lines[1]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-x/--xlines' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}
			break;

		case 't':
			z32 += 1;
			lines[2] = optarg;
			if (!(strpbrk(flag, lines[2]) == NULL)) {
				printf("\nНеверный ввод, аргумент '-t/--thicness' должен иметь числовое значение. Попробуйте еще раз\n");
				printf("Используйте ключ --help для вызова справки\n\n");
				return 0;
			}

			break;
		case 'c':
			z33 += 1;
			lines[3] = optarg;
			break;
		case 'f':
			zz1 += 1;
			break;
		case 'q':
			zz2 += 1;
			break;
		case 'h':
			DESCRIPTIONS();
			printHelp();
			return 0;
			break;
		case 'i':
			inf = 1;
			break;
		}
		opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
	}


	tokens ch = checking_values(argv, argc);
	argc -= optind;
	argv += optind;
	char* path_in = argv[0];
	char* path_out = argv[argc - 1];


	BMP img = read_image(path_in);
	if (inf) {
		printFileHeader(img.bfh);
		printInfoHeader(img.bih);
		return 0;
	}
	if (img.file_error == 1) {
		return 0;
	}


	for (int i = 0; i < argc; i++) {
		if (!strstr(argv[i], ".bmp")) {
			printf("\nВведите данные корректно, без лишних и неизвестных для программы ключей.\nИпользуйте ключ --help для вызова справки\n\n");
			return 0;
		}
	}


	if ((!path_out) || (!path_in) || (img.error_signal == 1) || (!strstr(path_out, ".bmp"))) {
		if ((img.error_signal == 1) && strstr(path_in, ".bmp")) {
			printf("\n%s - ошибка чтения файла.Такой файл отсутсвует в данной папке, проверьте правильность написания", path_in);
			printf("\nПо умолчанию первым аргументом должно быть передано имя читаемого bmp-файла\n");
			printf("Последним передается имя bmp-файла, в который будут записаны изменения\n");
			printf("Попробуйте снова (В данном формате: -//-.bmp)\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		printf("\nПо умолчанию первым аргументом должно быть передано имя читаемого bmp-файла\n");
		printf("Последним передается имя bmp-файла, в который будут записаны изменения\n");
		printf("Попробуйте снова (В данном формате: -//-.bmp)\n");
		printf("Используйте ключ --help для вызова справки\n\n");
		return 0;
	}


	if ((z11 == 1) || (z12 == 1)) {
		if ((z2 == 1) || (z30 == 1) || (z31 == 1) || (z32 == 1) || (z33 == 1)) {
			printf("\nВведите только те аргументы, которые указаны для данной функции\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if ((z11 == 1) && (z12 == 0)) {
			printf("\nНедостаточно аргументов. Попробуйте снова\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if ((z11 == 0) && (z12 == 1)) {
			printf("\nНедостаточно аргументов. Попробуйте снова\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}

		if (ch.error_flag == 0) {
			if (color_replacement(ch, img)) {
				write_image(path_out, img);
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}

	if (z2 > 0) {
		if ((z11 == 1) || (z12 == 1) || (z30 == 1) || (z31 == 1) || (z32 == 1) || (z33 == 1)) {
			printf("\nВведите только те аргументы, которые указаны для данной функции\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if (z2 > 1) {
			printf("\nВы можете ввести только один компонент RGB\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		int filter = filter_rgb_component(rgb_value, img);
		if (filter == 0) {
			return 0;
		}
		write_image(path_out, img);
	}

	if (z30 > 0 || z31 > 0 || z32 > 0 || z33 > 0) {
		if ((z11 == 1) || (z12 == 1) || (z2 == 1)) {
			printf("\nВведите только те аргументы, которые указаны для данной функции\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if (z30 == 0 || z31 == 0 || z32 == 0 || z33 == 0) {
			printf("\nОшибка при вводе аргументов, каждый аргумент используется один раз.Попробуйте снова\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if (z30 + z31 + z32 + z33 < 4) {
			printf("\nНедостаточно аргументов. Попробуйте снова\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}
		if (z30 + z31 + z32 + z33 > 4) {
			printf("\nОшибка при вводе аргументов, каждый аргумент используется один раз.Попробуйте снова\n");
			printf("Используйте ключ --help для вызова справки\n\n");
			return 0;
		}

		int cur = cut_on_lines(lines, img);
		if (cur)
			write_image(path_out, img);
		else
			return 0;
	}
	if (zz1 > 0) {
		if (b_w_filter(img)) {
			write_image(path_out, img);
		}
		else {
			return 0;
		}
	}
	if (zz2 > 0) {
		printf("Количество цветов в изображении равно %d", quantity_color(img));
		return 0;
	}
	if ((z11 == 0) && (z12 == 0) && (z2 == 0) && (z30 == 0) && (z31 == 0) && (z32 == 0) && (z33 == 0)) {
		write_image(path_out, img);
	}

	printf("\nРезультат успешно записан в файл - %s.\n\n", path_out);

	free(rgb_value);
	free(lines);
	free(img.arr);
	free(ch.tval_new);
	free(ch.tval_old);
	return 0;

}