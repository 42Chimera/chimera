#include "Chimera.h"

// https://docs.wxwidgets.org/3.0/overview_helloworld.html

class MainWindow : public Cm::Window
{
public: explicit MainWindow(CmString title, CmPoint location, CmSize winSize) noexcept
: Cm::Window(title, location, winSize)
{}

};

// createApplication은 따로 설정값이 app에 들어가서 별도로 구현하도록 뺀거 같은데. 우리는 굳이 createApplication이 필요할까?
int main(int ac, char** av)
{
  // https://wiki.qt.io/Qt_for_Beginners
  // 1.
  Cm::Application app (ac, av);

  // 2. Load init data (for example, model file...)
  //    이때, 프로세스를 하나 더 파서 앱 로딩 화면을 띄워줄 수 있음.
  app.Init();

  // 3. 메인 위도우 위젯 생성.
  MainWindow myWin (CmString("Name"), CmPoint(0, 0), CmSize(500, 500));
  myWin.Show();

  // 4. 앱 실행. (Loop)
  return app.Run();
}
