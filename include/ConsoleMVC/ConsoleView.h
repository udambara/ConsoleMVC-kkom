#pragma once

#include <string>
#include <vector>
#include "DataPersistence/Sample.h"

namespace cmvc {

class ConsoleView {
public:
    void PrintMainMenu() const;
    void PrintNotImplemented(const std::string& menuName) const;
    void PrintMessage(const std::string& message) const;
    void PrintError(const std::string& message) const;

    void PrintSampleMenu() const;
    void PrintSampleList(const std::vector<dp::Sample>& samples) const;
    dp::Sample ReadNewSample() const;
    std::string ReadSearchKeyword() const;
    int ReadDummyCount(const std::string& label) const;

    void PrintMonitoringMenu() const;

    // Reads an integer menu choice; re-prompts on invalid input.
    int ReadMenuChoice(const std::string& prompt) const;
};

}
