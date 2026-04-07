#pragma once

namespace Cat
{

enum class MouseCode : uint16_t
{
  // From glfw3.h 
  Button0                = 0,
  Button1                = 1,
  Button2                = 2,
  Button3                = 3,
  Button4                = 4,
  Button5                = 5,
  Button6                = 6,
  Button7                = 7,

  ButtonLast             = Button7,
  ButtonLeft             = Button0,
  ButtonRight            = Button1,
  ButtonMiddle           = Button2,
};

inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
{
  os << static_cast<int32_t>(mouseCode);
  return os;
}

}

#define C_BUTTON_0        ::Cat::MouseCode::Button0 /* Left Mouse Button */
#define C_BUTTON_1        ::Cat::MouseCode::Button1 /* Right Mouse Button */
#define C_BUTTON_2        ::Cat::MouseCode::Button2 /* Middle Mouse Button */
#define C_BUTTON_3        ::Cat::MouseCode::Button3 /* Extra Button */
#define C_BUTTON_4        ::Cat::MouseCode::Button4 /* Extra Button */
#define C_BUTTON_5        ::Cat::MouseCode::Button5 /* Extra Button */
#define C_BUTTON_6        ::Cat::MouseCode::Button6 /* Extra Button */
#define C_BUTTON_7        ::Cat::MouseCode::Button7 /* Extra Button */

#define C_BUTTON_LAST     C_BUTTON_7
#define C_BUTTON_LEFT     C_BUTTON_0
#define C_BUTTON_RIGHT    C_BUTTON_1
#define C_BUTTON_MIDDLE   C_BUTTON_2
