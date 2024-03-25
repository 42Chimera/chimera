#include "render/Renderer.h"
#include "render/RenderCommnad.h"
namespace Cm
{
Renderer::SceneData Renderer::sSceneData;
RenderAPI::API Renderer::GetAPI()
{
  return RenderAPI::GetAPI();
}

// 렌더링 전 설정해야되는 동작 모음
void Renderer::BegineScene( const std::unique_ptr<Camera>& camera )
{
  sSceneData.viewProjectionMatrix = camera->CalculateViewProjectionMatrix();
}
// 렌더링 끝난후 해야되는 동작 모응
void Renderer::EndScene() {}

// RednerCommand로 보낼 것
void Renderer::Submit( const std::unique_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray )
{
  // TODO:추후에 command queue로 렌더링 명령어를 쌓아두게 하고 다른 쓰레드에서 처리하는 방식을 채택할 수 있음
  // 현재는 단순히 그리는 함수 자체가 들어있는 상태

  // 쉐이더 프로그램 바인딩 후 uniform 셋팅을 해준다
  shader->Bind();
  shader->SetUniformMat4( "uViewProjection", sSceneData.viewProjectionMatrix );
  RenderCommand::DrawIndex( vertexArray );
}


}// namespace Cm