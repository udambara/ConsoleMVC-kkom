#include "ConsoleMVC/ApprovalController.h"

namespace cmvc {

void ApprovalController::Run() {
    while (true) {
        m_view.PrintApprovalMenu();
        int choice = m_view.ReadMenuChoice("선택: ");
        switch (choice) {
            case 1: HandleListReserved(); break;
            case 2: HandleApprove(); break;
            case 3: HandleReject(); break;
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

void ApprovalController::HandleListReserved() {
    std::vector<dp::Order> reserved = m_orderRepo.GetByStatus(dp::OrderStatus::RESERVED);
    m_view.PrintOrderTable(reserved, m_sampleRepo);
}

void ApprovalController::HandleApprove() {
    std::vector<dp::Order> reserved = m_orderRepo.GetByStatus(dp::OrderStatus::RESERVED);
    m_view.PrintOrderTable(reserved, m_sampleRepo);
    if (reserved.empty()) {
        return;
    }

    int selection = m_view.ReadIndexChoice(static_cast<int>(reserved.size()), "승인할 주문 번호");
    if (selection == 0) {
        return;
    }

    dp::Order order = reserved[selection - 1];
    m_workflow.Approve(order);
    m_view.PrintMessage("주문을 승인 처리했습니다: " + order.orderNo);
}

void ApprovalController::HandleReject() {
    std::vector<dp::Order> reserved = m_orderRepo.GetByStatus(dp::OrderStatus::RESERVED);
    m_view.PrintOrderTable(reserved, m_sampleRepo);
    if (reserved.empty()) {
        return;
    }

    int selection = m_view.ReadIndexChoice(static_cast<int>(reserved.size()), "거절할 주문 번호");
    if (selection == 0) {
        return;
    }

    dp::Order order = reserved[selection - 1];
    m_workflow.Reject(order);
    m_view.PrintMessage("주문을 거절 처리했습니다: " + order.orderNo);
}

}
