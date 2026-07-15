#include "ConsoleMVC/ProductionController.h"

#include <algorithm>
#include <optional>

namespace cmvc {

void ProductionController::Run() {
    while (true) {
        m_view.PrintProductionMenu();
        int choice = m_view.ReadMenuChoice("선택: ");

        std::vector<dp::Order> producing = m_orderRepo.GetByStatus(dp::OrderStatus::PRODUCING);

        switch (choice) {
            case 1: {
                auto it = std::find_if(producing.begin(), producing.end(),
                                        [](const dp::Order& o) { return o.productionStartEpochSec > 0; });
                std::optional<dp::Order> current = it != producing.end() ? std::optional<dp::Order>(*it) : std::nullopt;
                m_view.PrintProductionStatus(current, m_sampleRepo);
                break;
            }
            case 2: {
                std::vector<dp::Order> waiting;
                for (const dp::Order& order : producing) {
                    if (order.productionStartEpochSec == 0) {
                        waiting.push_back(order);
                    }
                }
                m_view.PrintWaitingQueue(waiting, m_sampleRepo);
                break;
            }
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

}
