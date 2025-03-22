#version 330 core
out vec4 FragColor; // Выходной цвет фрагмента

uniform float time; // Время для анимации
uniform vec2 resolution; // Разрешение экрана

void main() {
    // Нормализованные координаты фрагмента (от 0 до 1)
    vec2 uv = gl_FragCoord.xy / resolution;

    // Эффект ряби: искажаем координаты с помощью синуса
    float ripple = sin(uv.x * 10.0 + time * 5.0) * 0.02; // Амплитуда и частота ряби
    uv.y += ripple; // Применяем искажение по оси Y

    // Цвет, зависящий от искаженных координат
    vec3 color = vec3(uv.x, uv.y, 0.5 + 0.5 * sin(time)); // Динамический цвет

    FragColor = vec4(color, 1.0); // Устанавливаем цвет фрагмента
}