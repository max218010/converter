#pragma once
#include "app.h"
#include "converter.h"
#include "DecToHex.h"
#include "HexToDec.h"
#include "DecToBin.h"
#include "BinToDec.h"  
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

    const char* opties[] = { "hex to dec", "dec to hex", "dec to bin", "bin to dec"};
    static int gekozen = 0;
    ImGui::Combo("Conversion", &gekozen, opties, IM_ARRAYSIZE(opties));

    bool enterPressed = ImGui::IsKeyPressed(ImGuiKey_Enter);

    if (ImGui::Button("Convert") || enterPressed)
    {
		//maak lege pointers
        std::unique_ptr<Converter<int>> fromInt;
        std::unique_ptr<Converter<std::string>> fromStr;
        std::string conversionEntry;

		//maak gekozen converter aan
        if (gekozen == 0) fromStr = std::make_unique<HexToDec>();
        if (gekozen == 1) fromInt = std::make_unique<DecToHex>();
        if (gekozen == 2) fromInt = std::make_unique<DecToBin>();
        if (gekozen == 3) fromStr = std::make_unique<BinToDec>();

        // valid check
        if ((fromInt && !fromInt->isValid(buffer)) ||
            (fromStr && !fromStr->isValid(buffer)))
        {
            result = "Invalid input";
        }
        else{
            try
            {
                // Convert & fill conversionlog
                if (fromInt) {
                    int value = std::stoi(buffer);
                    result = fromInt->convert(value);

                    // Zet conversionEntry voor logging
                    if (gekozen == 1) conversionEntry = "DEC -> HEX: " + std::string(buffer) + " = " + result;
                    else if (gekozen == 2) conversionEntry = "DEC -> BIN: " + std::string(buffer) + " = " + result;

                }
                else if (fromStr) {
                    result = fromStr->convert(buffer);

                    if (gekozen == 0) conversionEntry = "HEX -> DEC: " + std::string(buffer) + " = " + result;
                    else if (gekozen == 3) conversionEntry = "BIN -> DEC: " + std::string(buffer) + " = " + result;
                }
                //logging
                std::thread logThread(logging, conversionEntry);
                logThread.detach(); 
            }
            catch (...) {
                result = "calculation error";
            }


        }
    }


    ImGui::Text("Result: %s", result.c_str());
    ImGui::End();
}


