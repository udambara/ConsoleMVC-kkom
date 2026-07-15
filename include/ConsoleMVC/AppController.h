#pragma once

#include "ConsoleMVC/ConsoleView.h"
#include "ConsoleMVC/SampleController.h"
#include "ConsoleMVC/MonitoringController.h"
#include "ConsoleMVC/OrderController.h"
#include "ConsoleMVC/ApprovalController.h"
#include "ConsoleMVC/ShippingController.h"
#include "ConsoleMVC/ProductionController.h"
#include "DataPersistence/SampleRepository.h"
#include "DataPersistence/OrderRepository.h"
#include "DataPersistence/OrderWorkflow.h"

namespace cmvc {

class AppController {
public:
    // Runs the main menu loop until the user chooses to exit.
    void Run();

private:
    ConsoleView m_view;
    SampleController m_sampleController;
    MonitoringController m_monitoringController;
    OrderController m_orderController;
    ApprovalController m_approvalController;
    ShippingController m_shippingController;
    ProductionController m_productionController;

    dp::SampleRepository m_sampleRepo;
    dp::OrderRepository m_orderRepo;
    dp::OrderWorkflow m_workflow{m_sampleRepo, m_orderRepo};
};

}
