#include "ConsoleMVC/AppController.h"

namespace cmvc {

void AppController::Run() {
    while (true) {
        m_view.PrintMainMenu();
        int choice = m_view.ReadMenuChoice("선택: ");
        switch (choice) {
            case 1: m_sampleController.Run(); break;
            case 2: m_view.PrintNotImplemented("시료주문"); break;
            case 3: m_view.PrintNotImplemented("시료승인/거절"); break;
            case 4: m_monitoringController.Run(); break;
            case 5: m_view.PrintNotImplemented("출고처리"); break;
            case 6: m_view.PrintNotImplemented("생산라인"); break;
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

}
