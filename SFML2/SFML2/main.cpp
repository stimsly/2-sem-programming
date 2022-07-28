#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
	RenderWindow win(VideoMode(900, 900), "SFML Window", Style::None);
	win.setFramerateLimit(60);

	CircleShape circ;
	circ.setRadius(100);
	circ.setPosition(100, 400);
	circ.setFillColor(Color(150, 50, 100));
	circ.setOrigin(100, 100);

	Clock clc;
	int circle_speed = 150;

	bool drag = false;
	Vector2i click_offs;
	double dy = 0;
	bool onGround = true;
	while (win.isOpen()) {
		Event ev;
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed)
				win.close();
			if (ev.type == Event::KeyPressed)
			{
				if (ev.key.code == Keyboard::Key::U) {
					circ.setFillColor(Color::Magenta);
					cout << "Color: magenta!" << endl;
				}
			}
			if (ev.type == Event::KeyReleased)
			{
				if (ev.key.code == Keyboard::Key::U) {
					circ.setFillColor(Color(150, 50, 100));
					cout << "Color: hz!" << endl;
				}
			}
			if (ev.type == Event::MouseButtonPressed) {
				if (ev.mouseButton.button == Mouse::Left) {
					Vector2i mouse_pos = Mouse::getPosition() - win.getPosition();
					Vector2f circle_pos = circ.getPosition();
					auto dist = (mouse_pos.x - circle_pos.x) * (mouse_pos.x - circle_pos.x) + (mouse_pos.y - circle_pos.y) * (mouse_pos.y - circle_pos.y);
					if (dist < 10000) {
						drag = true;
						click_offs = Vector2i(circle_pos.x - mouse_pos.x, circle_pos.y - mouse_pos.y);
						cout << click_offs.x << " " << click_offs.y << endl;
					}
				}
			}

			if (ev.type == Event::MouseButtonReleased) {
				if (drag) {
					drag = false;
				}
			}
		}

		float elapsed = clc.restart().asMilliseconds();


		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			onGround = false;
			dy = -5;
		}
		if (!onGround)
			dy += elapsed * 0.005;

		circ.move(0, dy);

		if (circ.getPosition().y > 300) {
			onGround = true;
			dy = 0;
		}



		Vector2i mouse_pos = Mouse::getPosition() - win.getPosition();
		Vector2f circle_pos = circ.getPosition();
		auto dist = (mouse_pos.x - circle_pos.x) * (mouse_pos.x - circle_pos.x) + (mouse_pos.y - circle_pos.y) * (mouse_pos.y - circle_pos.y);
		if (dist < 10000) {
			circ.setFillColor(Color::Red);
		}
		else {
			circ.setFillColor(Color(150, 50, 100));
		}

		if (drag)
			circ.setPosition(mouse_pos.x + click_offs.x, mouse_pos.y + click_offs.y);

		if (Keyboard::isKeyPressed(Keyboard::Key::D))
			circ.move(circle_speed * elapsed / 1000, 0);
		if (Keyboard::isKeyPressed(Keyboard::Key::A))
			circ.move(-circle_speed * elapsed / 1000, 0);



		win.clear(Color(50, 50, 50));
		win.draw(circ);

		win.display();


	}

	return 0;
}