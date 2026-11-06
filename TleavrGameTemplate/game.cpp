#include "raylib.h"
#include "font_data.h"

int main(void) {
    InitWindow(1280, 720, "Tleavr");
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    // الحروف اللي بيحملها الخط (إنجليزي هنا)
    static int cps[256];
    int nc = 0;
    for (int c = 32; c <= 126; c++) cps[nc++] = c;

    // تحميل الخط المدمج بحجم 96
    Font font = LoadFontFromMemory(".ttf", FONT_DATA, FONT_DATA_LEN, 96, cps, nc);
    SetTextureFilter(font.texture, TEXTURE_FILTER_BILINEAR);

    const char* text = "Tleavr";
    const float size = 96.0f;
    const float spacing = 2.0f;

    while (!WindowShouldClose()) {
        // حساب حجم النص عشان نوسّطه
        Vector2 m = MeasureTextEx(font, text, size, spacing);
        Vector2 pos = {
            ((float)GetScreenWidth() - m.x) / 2.0f,
            ((float)GetScreenHeight() - m.y) / 2.0f
        };

        BeginDrawing();
        ClearBackground(Color{ 18, 20, 28, 255 });
        DrawTextEx(font, text, pos, size, spacing, Color{ 235, 238, 245, 255 });
        EndDrawing();
    }

    UnloadFont(font);
    CloseWindow();
    return 0;
}