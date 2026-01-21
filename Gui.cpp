#pragma once
#include "app.h"
#include "converter.h"
#include "DecToHex.h"
#include "HexToDec.h"
#include "DecToBin.h"
#include <fstream>
#include <thread>
#include <imgui.h>
#include <string>





void logging(const std::string& conversion) {
    std::ofstream   cSchrijven("log.txt", std::ios::app);
    if (cSchrijven)
    {
        cSchrijven << conversion << std::endl;
        cSchrijven.close();
    }
}


void app::update()
{
    ImGui::Begin("Main");
	static int value = 0;
    static char buffer[256]{};
    static std::string result;

    ImGui::InputText("Input", buffer, sizeof(buffer));

    const char* opties[] = { "hex to dec", "dec to hex", "dec to bin"};
    static int gekozen = 0;
    ImGui::Combo("Conversion", &gekozen, opties, IM_ARRAYSIZE(opties));

    if (ImGui::Button("Convert"))
    {
        // 1. Kies converter op basis van gekozen optie
        std::unique_ptr<Converter<int>> fromInt;
        std::unique_ptr<Converter<std::string>> fromStr;
        std::string conversionEntry;

        if (gekozen == 0) fromStr = std::make_unique<HexToDec>();
        if (gekozen == 1) fromInt = std::make_unique<DecToHex>();
        if (gekozen == 2) fromInt = std::make_unique<DecToBin>();

        // 2. Check input via converter
        if ((fromInt && !fromInt->isValid(buffer)) ||
            (fromStr && !fromStr->isValid(buffer)))
        {
            result = "Invalid input";
        }
        else{
            // 3. Convert
            if (fromInt) {
                int value = std::stoi(buffer);
                result = fromInt->convert(value);
            }
            else if (fromStr) {
                result = fromStr->convert(buffer);
            }
            std::thread logThread(logging, conversionEntry);
            logThread.detach(); // let it run independently
        }
    }


    ImGui::Text("Result: %s", result.c_str());
    ImGui::End();
}


