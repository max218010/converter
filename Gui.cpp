#include "app.h"
#include "converter.h"
#include "DecToHex.h"
#include "HexToDec.h"

#include <imgui.h>
#include <string>

void app::update()
{
    ImGui::Begin("Main");

    static char buffer[256]{};
    static std::string result;

    ImGui::InputText("Input", buffer, sizeof(buffer));

    const char* opties[] = { "hex to dec", "dec to hex" };
    static int gekozen = 0;
    ImGui::Combo("Conversion", &gekozen, opties, IM_ARRAYSIZE(opties));

    if (ImGui::Button("Convert"))
    {
        try
        {
            int value;
            std::unique_ptr<Converter> converter;

            if (gekozen == 0)
            {
                value = std::stoi(buffer, nullptr, 16);
                converter = std::make_unique<HexToDec>();
            }
            else
            {
                value = std::stoi(buffer);
                converter = std::make_unique<DecToHex>();
            }

            result = converter->convert(value);
        }
        catch (...)
        {
            result = "Invalid input";
        }
    }

    ImGui::Text("Result: %s", result.c_str());
    ImGui::End();
}
