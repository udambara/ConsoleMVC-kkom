# ConsoleMVC 구현 계획

1. 프로젝트 구조 설정 - Model / View / Controller 패키지(네임스페이스) 분리
2. Model 정의 - Sample, Order 도메인 객체
3. View 구현 - 6개 메인 메뉴 및 서브 메뉴 콘솔 출력, 사용자 입력 수신
4. Controller 구현 - 메뉴 선택에 따른 흐름 제어, 입력값 검증, Model과 View 연결
5. 외부 연동 인터페이스 정의 - DataPersistence(저장/조회), DataMonitor(모니터링 조회) 호출 지점 정의 (실제 구현은 각 서브모듈에서 진행)
