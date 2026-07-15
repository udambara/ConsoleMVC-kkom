#pragma once

#include "ConsoleMVC/ConsoleView.h"
#include "DataPersistence/SampleRepository.h"
#include "DataPersistence/OrderRepository.h"
#include "DataPersistence/OrderWorkflow.h"

namespace cmvc {

class ApprovalController {
public:
    // Runs the approval/rejection submenu loop until the user chooses to go back.
    void Run();

private:
    dp::SampleRepository m_sampleRepo;
    dp::OrderRepository m_orderRepo;
    dp::OrderWorkflow m_workflow{m_sampleRepo, m_orderRepo};
    ConsoleView m_view;

    void HandleListReserved();
    void HandleApprove();
    void HandleReject();
};

}
