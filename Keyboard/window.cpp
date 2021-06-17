#include "windows.h"
#include "iostream"
#include "fstream"
#include "string"
#include "stdlib.h"
#include "time.h"

class Keyboard : sf::RectangleShape {
    sf::Font font;

public:
    int x, y; //размеры кнопки
    int n_x, n_y; //матричная сетка
    sf::RectangleShape button;
    sf::Text text;

    void set_value(int a = 0, int b = 0, int c = 0, int d = 0){
        n_x = a;
        n_y = b;
        x = c;
        y = d;
    }

    void draw_button(sf::Vector2f size = sf::Vector2f(70, 70)){
        button.setSize(size);
        button.setFillColor(sf::Color::White);
        button.setPosition(200 + 77*n_x + x, 450 + 77*n_y + y);
        button.setOutlineColor(sf::Color::Black);
        button.setOutlineThickness(2);
    }

    void draw_text(std::string s){
        font.loadFromFile("Font/Arial.ttf");
        text.setString(s);
        text.setFont(font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Black);
        text.setPosition(button.getPosition().x - text.getGlobalBounds().width/2 + button.getGlobalBounds().width/2, button.getPosition().y + text.getGlobalBounds().height/2 );
    }

};

void get_from_file(char *text, int begin = 1, int count = 70){
    std::ifstream in;
    in.open("text.txt");
    in.seekg(begin);
    if (in.is_open()) {
        in.getline(text, count + 1);
    }
    in.close();
}

int get_random(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

void get_text_1(sf::Text &t, int begin)
{
    char text[120] = "";
    get_from_file(text, begin, 0);
    t.setString(text);
    t.setColor(sf::Color::Green);
}

void get_text_2(sf::Text &t2, sf::Text t1, sf::Vector2f t_pos, int begin)
{
    char text_2[120];
    std::string s = t1.getString();
    int n = s.length();

    get_from_file(text_2, begin + n, 70 - n);
    t2.setString(text_2);
    t2.setColor(sf::Color::Black);
    t2.setPosition(t_pos.x + t1.getGlobalBounds().width + t1.getLetterSpacing(), t_pos.y);
}

void change(sf::Text &t1, sf::Text &t2){
    std::string s1 = t1.getString();
    std::string s2 = t2.getString();

    s1.push_back(s2[0]);
    s2.erase(0, 1);

    t1.setString(s1);
    t2.setString(s2);
    t2.setPosition(t1.getPosition().x + t1.getGlobalBounds().width + 2, t1.getPosition().y);
}
