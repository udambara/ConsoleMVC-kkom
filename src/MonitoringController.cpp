#include "ConsoleMVC/MonitoringController.h"
#include "DataMonitor/DataMonitor.h"

namespace cmvc {

void MonitoringController::Run() {
    while (true) {
        m_view.PrintMonitoringMenu();
        int choice = m_view.ReadMenuChoice("선택: ");
        switch (choice) {
            case 1: mon::PrintOrderStatusTable(m_orderRepo); break;
            case 2: mon::PrintInventoryTable(m_sampleRepo); break;
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

}
