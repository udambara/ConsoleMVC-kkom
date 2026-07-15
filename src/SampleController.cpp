#include "ConsoleMVC/SampleController.h"
#include "DummyDataGenerator/DummyDataGenerator.h"

namespace cmvc {

void SampleController::Run() {
    while (true) {
        m_view.PrintSampleMenu();
        int choice = m_view.ReadMenuChoice("선택: ");
        switch (choice) {
            case 1: HandleRegister(); break;
            case 2: HandleList(); break;
            case 3: HandleSearch(); break;
            case 4: HandleGenerateDummyData(); break;
            case 0: return;
            default: m_view.PrintError("올바른 메뉴 번호를 선택해주세요."); break;
        }
    }
}

void SampleController::HandleRegister() {
    dp::Sample sample = m_view.ReadNewSample();
    std::string errorMessage;
    if (m_sampleRepo.Add(sample, errorMessage)) {
        m_view.PrintMessage("시료가 등록되었습니다: " + sample.id);
    } else {
        m_view.PrintError(errorMessage);
    }
}

void SampleController::HandleList() {
    m_view.PrintSampleList(m_sampleRepo.GetAll());
}

void SampleController::HandleSearch() {
    std::string keyword = m_view.ReadSearchKeyword();
    m_view.PrintSampleList(m_sampleRepo.FindByName(keyword));
}

void SampleController::HandleGenerateDummyData() {
    int sampleCount = m_view.ReadDummyCount("시료");
    ddg::GenerateDummySamples(m_sampleRepo, sampleCount);

    int orderCount = m_view.ReadDummyCount("주문");
    ddg::GenerateDummyOrders(m_sampleRepo, m_orderRepo, orderCount);

    m_view.PrintMessage("더미 데이터 생성 완료: 시료 " + std::to_string(sampleCount) +
                         "건, 주문 " + std::to_string(orderCount) + "건");
}

}
