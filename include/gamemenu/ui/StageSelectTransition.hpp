#ifndef STAGE_SELECT_TRANSITION_H_
#define STAGE_SELECT_TRANSITION_H_

#include <critter/ui/UIObject.hpp>

#include <gamemenu/ui/CourseSelectGroup.hpp>
#include <gamemenu/ui/StageBanner.hpp>

namespace gamemenu {
namespace ui {

class StageSelectTransition : public ::monkeysworld::critter::ui::UIObject {
 public:
  StageSelectTransition(::monkeysworld::engine::Context* ctx);

  void Create() override;
  void Update() override;

  // draw nothing
  void DrawUI(glm::vec2, glm::vec2, ::monkeysworld::shader::Canvas) override {};

  /**
   *  Begins tne process of transitioning to the next screen.
   */ 
  void StartTransition();
 private:
  bool timer_started_;
  float local_delta_;

  bool banner_swapped_;
  
  std::shared_ptr<CourseSelectGroup> stage_select_;
  std::shared_ptr<StageBanner> banner_;
  std::shared_ptr<::monkeysworld::critter::ui::UIObject> bg_;
  
};

}
}

#endif