#pragma once

namespace Cat
{

enum class KeyCode : uint16_t
{
  // From glfw3.h
  Space              = 32,
  Apostrophe         = 39,  /* ' */
  Comma              = 44,  /* , */
  Minus              = 45,  /* - */
  Period             = 46,  /* . */
  Slash              = 47,  /* / */
  D0                 = 48,
  D1                 = 49,
  D2                 = 50,
  D3                 = 51,
  D4                 = 52,
  D5                 = 53,
  D6                 = 54,
  D7                 = 55,
  D8                 = 56,
  D9                 = 57,
  SEMICOLON          = 59,  /* ; */
  EQUAL              = 61,  /* = */
  A                  = 65,
  B                  = 66,
  C                  = 67,
  D                  = 68,
  E                  = 69,
  F                  = 70,
  G                  = 71,
  H                  = 72,
  I                  = 73,
  J                  = 74,
  K                  = 75,
  L                  = 76,
  M                  = 77,
  N                  = 78,
  O                  = 79,
  P                  = 80,
  Q                  = 81,
  R                  = 82,
  S                  = 83,
  T                  = 84,
  U                  = 85,
  V                  = 86,
  W                  = 87,
  X                  = 88,
  Y                  = 89,
  Z                  = 90,
  LeftBracket        = 91,  /* [ */
  Backslash          = 92,  /* \ */
  RightBracket       = 93,  /* ] */
  GraceAccent        = 96,  /* ` */
  World1             = 161, /* non-US #1 */
  World2             = 162, /* non-US #2 */

  /* Function keys */
  Escape             = 256,
  Enter              = 257,
  Tab                = 258,
  Backspace          = 259,
  Insert             = 260,
  Delete             = 261,
  Right              = 262,
  Left               = 263,
  Down               = 264,
  Up                 = 265,
  PageUp             = 266,
  PageDown           = 267,
  Home               = 268,
  End                = 269,
  CapsLock           = 280,
  ScrollLock         = 281,
  NumLock            = 282,
  PrintScreen        = 283,
  Pause              = 284,
  F1                 = 290,
  F2                 = 291,
  F3                 = 292,
  F4                 = 293,
  F5                 = 294,
  F6                 = 295,
  F7                 = 296,
  F8                 = 297,
  F9                 = 298,
  F10                = 299,
  F11                = 300,
  F12                = 301,
  F13                = 302,
  F14                = 303,
  F15                = 304,
  F16                = 305,
  F17                = 306,
  F18                = 307,
  F19                = 308,
  F20                = 309,
  F21                = 310,
  F22                = 311,
  F23                = 312,
  F24                = 313,
  F25                = 314,
  KP_0               = 320,
  KP_1               = 321,
  KP_2               = 322,
  KP_3               = 323,
  KP_4               = 324,
  KP_5               = 325,
  KP_6               = 326,
  KP_7               = 327,
  KP_8               = 328,
  KP_9               = 329,
  KPDecimal          = 330,
  KPDivide           = 331,
  KPMultiply         = 332,
  KPSubtract         = 333,
  KPAdd              = 334,
  KPEnter            = 335,
  KPEqual            = 336,
  LeftShift          = 340,
  LeftControl        = 341,
  LeftAlt            = 342,
  LeftSuper          = 343,
  RightShift         = 344,
  RightControl       = 345,
  RightAlt           = 346,
  RightSuper         = 347,
  Menu               = 348,

  ModShift           = 0x0001,
  ModControl         = 0x0002,
  ModAlt             = 0x0004,
  ModSuper           = 0x0008,
  ModCapsLock        = 0x0010,
  ModNumLock         = 0x0020,

};

inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
{
  os << static_cast<uint32_t>(keyCode);
  return os;
}
}
// From glfw3.h
#define C_SPACE           ::Cat::KeyCode::Space
#define C_APOSTROPHE      ::Cat::KeyCode::Apostrophe    /* ' */
#define C_COMMA           ::Cat::KeyCode::Comma         /* , */
#define C_MINUS           ::Cat::KeyCode::Minus         /* - */
#define C_PERIOD          ::Cat::KeyCode::Period        /* . */
#define C_SLASH           ::Cat::KeyCode::Slash         /* / */
#define C_0               ::Cat::KeyCode::D0
#define C_1               ::Cat::KeyCode::D1
#define C_2               ::Cat::KeyCode::D2
#define C_3               ::Cat::KeyCode::D3
#define C_4               ::Cat::KeyCode::D4
#define C_5               ::Cat::KeyCode::D5
#define C_6               ::Cat::KeyCode::D6
#define C_7               ::Cat::KeyCode::D7
#define C_8               ::Cat::KeyCode::D8
#define C_9               ::Cat::KeyCode::D9
#define C_SEMICOLON       ::Cat::KeyCode::Semicolon     /* ; */
#define C_EQUAL           ::Cat::KeyCode::Equal         /* = */
#define C_A               ::Cat::KeyCode::A
#define C_B               ::Cat::KeyCode::B
#define C_C               ::Cat::KeyCode::C
#define C_D               ::Cat::KeyCode::D
#define C_E               ::Cat::KeyCode::E
#define C_F               ::Cat::KeyCode::F
#define C_G               ::Cat::KeyCode::G
#define C_H               ::Cat::KeyCode::H
#define C_I               ::Cat::KeyCode::I
#define C_J               ::Cat::KeyCode::J
#define C_K               ::Cat::KeyCode::K
#define C_L               ::Cat::KeyCode::L
#define C_M               ::Cat::KeyCode::M
#define C_N               ::Cat::KeyCode::N
#define C_O               ::Cat::KeyCode::O
#define C_P               ::Cat::KeyCode::P
#define C_Q               ::Cat::KeyCode::Q
#define C_R               ::Cat::KeyCode::R
#define C_S               ::Cat::KeyCode::S
#define C_T               ::Cat::KeyCode::T
#define C_U               ::Cat::KeyCode::U
#define C_V               ::Cat::KeyCode::V
#define C_W               ::Cat::KeyCode::W
#define C_X               ::Cat::KeyCode::X
#define C_Y               ::Cat::KeyCode::Y
#define C_Z               ::Cat::KeyCode::Z
#define C_LEFT_BRACKET    ::Cat::KeyCode::LeftBracket   /* [ */
#define C_BACKSLASH       ::Cat::KeyCode::Backslash     /* \ */
#define C_RIGHT_BRACKET   ::Cat::KeyCode::RightBracket  /* ] */
#define C_GRAVE_ACCENT    ::Cat::KeyCode::GraveAccent   /* ` */
#define C_WORLD_1         ::Cat::KeyCode::World1        /* non-US #1 */
#define C_WORLD_2         ::Cat::KeyCode::World2        /* non-US #2 */

/* Function keys */
#define C_ESCAPE          ::Cat::KeyCode::Escape
#define C_ENTER           ::Cat::KeyCode::Enter
#define C_TAB             ::Cat::KeyCode::Tab
#define C_BACKSPACE       ::Cat::KeyCode::Backspace
#define C_INSERT          ::Cat::KeyCode::Insert
#define C_DELETE          ::Cat::KeyCode::Delete
#define C_RIGHT           ::Cat::KeyCode::Right
#define C_LEFT            ::Cat::KeyCode::Left
#define C_DOWN            ::Cat::KeyCode::Down
#define C_UP              ::Cat::KeyCode::Up
#define C_PAGE_UP         ::Cat::KeyCode::PageUp
#define C_PAGE_DOWN       ::Cat::KeyCode::PageDown
#define C_HOME            ::Cat::KeyCode::Home
#define C_END             ::Cat::KeyCode::End
#define C_CAPS_LOCK       ::Cat::KeyCode::CapsLock
#define C_SCROLL_LOCK     ::Cat::KeyCode::ScrollLock
#define C_NUM_LOCK        ::Cat::KeyCode::NumLock
#define C_PRINT_SCREEN    ::Cat::KeyCode::PrintScreen
#define C_PAUSE           ::Cat::KeyCode::Pause
#define C_F1              ::Cat::KeyCode::F1
#define C_F2              ::Cat::KeyCode::F2
#define C_F3              ::Cat::KeyCode::F3
#define C_F4              ::Cat::KeyCode::F4
#define C_F5              ::Cat::KeyCode::F5
#define C_F6              ::Cat::KeyCode::F6
#define C_F7              ::Cat::KeyCode::F7
#define C_F8              ::Cat::KeyCode::F8
#define C_F9              ::Cat::KeyCode::F9
#define C_F10             ::Cat::KeyCode::F10
#define C_F11             ::Cat::KeyCode::F11
#define C_F12             ::Cat::KeyCode::F12
#define C_F13             ::Cat::KeyCode::F13
#define C_F14             ::Cat::KeyCode::F14
#define C_F15             ::Cat::KeyCode::F15
#define C_F16             ::Cat::KeyCode::F16
#define C_F17             ::Cat::KeyCode::F17
#define C_F18             ::Cat::KeyCode::F18
#define C_F19             ::Cat::KeyCode::F19
#define C_F20             ::Cat::KeyCode::F20
#define C_F21             ::Cat::KeyCode::F21
#define C_F22             ::Cat::KeyCode::F22
#define C_F23             ::Cat::KeyCode::F23
#define C_F24             ::Cat::KeyCode::F24
#define C_F25             ::Cat::KeyCode::F25

/* Keypad */
#define C_KP_0            ::Cat::KeyCode::KP0
#define C_KP_1            ::Cat::KeyCode::KP1
#define C_KP_2            ::Cat::KeyCode::KP2
#define C_KP_3            ::Cat::KeyCode::KP3
#define C_KP_4            ::Cat::KeyCode::KP4
#define C_KP_5            ::Cat::KeyCode::KP5
#define C_KP_6            ::Cat::KeyCode::KP6
#define C_KP_7            ::Cat::KeyCode::KP7
#define C_KP_8            ::Cat::KeyCode::KP8
#define C_KP_9            ::Cat::KeyCode::KP9
#define C_KP_DECIMAL      ::Cat::KeyCode::KPDecimal
#define C_KP_DIVIDE       ::Cat::KeyCode::KPDivide
#define C_KP_MULTIPLY     ::Cat::KeyCode::KPMultiply
#define C_KP_SUBTRACT     ::Cat::KeyCode::KPSubtract
#define C_KP_ADD          ::Cat::KeyCode::KPAdd
#define C_KP_ENTER        ::Cat::KeyCode::KPEnter
#define C_KP_EQUAL        ::Cat::KeyCode::KPEqual

#define C_LEFT_SHIFT      ::Cat::KeyCode::LeftShift
#define C_LEFT_CONTROL    ::Cat::KeyCode::LeftControl
#define C_LEFT_ALT        ::Cat::KeyCode::LeftAlt
#define C_LEFT_SUPER      ::Cat::KeyCode::LeftSuper
#define C_RIGHT_SHIFT     ::Cat::KeyCode::RightShift
#define C_RIGHT_CONTROL   ::Cat::KeyCode::RightControl
#define C_RIGHT_ALT       ::Cat::KeyCode::RightAlt
#define C_RIGHT_SUPER     ::Cat::KeyCode::RightSuper
#define C_MENU            ::Cat::KeyCode::Menu
