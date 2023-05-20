SET(SOURCES screens/ui_SplashScreen.c
    screens/ui_HomeScreen.c
    ui.c
    ui_helpers.c)

add_library(ui ${SOURCES})
