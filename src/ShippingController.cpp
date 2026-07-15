#include "ConsoleMVC/ShippingController.h"

#include <ctime>

namespace cmvc {

void ShippingController::Run() {
    while (true) {
        m_view.PrintShippingMenu();
        int choice = m_view.ReadMenuChoice("선택: ");
        switch (choice) {
            case 1: HandleListConfirmed(); break;
            case 2: HandleRelease(); break;
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

void ShippingController::HandleListConfirmed() {
    std::vector<dp::Order> confirmed = m_orderRepo.GetByStatus(dp::OrderStatus::CONFIRMED);
    m_view.PrintOrderTable(confirmed, m_sampleRepo);
}

void ShippingController::HandleRelease() {
    std::vector<dp::Order> confirmed = m_orderRepo.GetByStatus(dp::OrderStatus::CONFIRMED);
    m_view.PrintOrderTable(confirmed, m_sampleRepo);
    if (confirmed.empty()) {
        return;
    }

    int selection = m_view.ReadIndexChoice(static_cast<int>(confirmed.size()), "출고할 주문 번호");
    if (selection == 0) {
        return;
    }

    dp::Order order = confirmed[selection - 1];

    std::string errorMessage;
    if (!m_sampleRepo.AdjustStock(order.sampleId, -order.quantity, errorMessage)) {
        m_view.PrintError(errorMessage);
        return;
    }

    order.status = dp::OrderStatus::RELEASE;
    order.releasedQty = order.quantity;
    order.releasedAtEpochSec = static_cast<long long>(std::time(nullptr));
    m_orderRepo.Update(order);

    m_view.PrintShippingResult(order);
}

}
