#pragma once
#include "ElemL1.h"
#include <fstream>
#include "form.h"
void InputC(R_Channel** h, std::fstream& f);
void InputA(ads** h, std::fstream& f);
void filling(R_Channel** h, ads** m, std::fstream& f);
void OutputMain(R_Channel* ch, std::fstream& f);
void OutputAssistive(ads* ad, std::fstream& f);
void Outputcosole(ElemL1* h, std::fstream& f);
void OutputInterface(R_Channel* ch, std::fstream& f);
void OutputSchedule(R_Channel* ch, std::fstream& f);
void Output(ElemL1* h, std::fstream& f);
void Delete(ElemL1** h);
void DeleteA(ads** h);
void DeleteT(timing** h);
void DeleteG(group_of_ads** h);
void DeleteC(R_Channel** h);