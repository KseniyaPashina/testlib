#include "SFML/Graphics.hpp"
#include "windows.h"
#include "iostream"
#include "fstream"
#include "string"
#include "stdlib.h"
#include "time.h"

/**
 * Keyboard is a class, which defines buttons with text
 * each button has got some parameters:
 * font - responsible for the font of a text (private)
 * x - responsible for shift of the button from zero value along Ox
 * y - responsible for shift of the button from zero value along Oy
 * n_x - responsible for coordinate Ox
 * n_y - responsible for coordinate Oy
 * button - responsible for creating rectangle
 * text - responsible for creating text
 */
class Keyboard : sf::RectangleShape {
    ///font of the text
    sf::Font font;

public:
    ///responsible for shift of the button from zero value
    int x, y;
    ///responsible for coordinate
    int n_x, n_y;
    ///responsible for creating rectangle
    sf::RectangleShape button;
    ///responsible for creating text
    sf::Text text;
    
    /**
     * set_value gets and sets the coordinate and offset value
     *
     * @param a - responsible for coordinate Ox
     * @param b - responsible for coordinate Oy
     * @param c - responsible for shift of the button from zero value along Ox
     * @param d - responsible for shift of the button from zero value along Oy
     */
    void set_value(int a = 0, int b = 0, int c = 0, int d = 0){
        n_x = a;
        n_y = b;
        x = c;
        y = d;
    }
    
    /**
     * draw_button creates a rectangle and gives it a position
     * @param size - responsible for the dimensions of the rectangle
     */
    void draw_button(sf::Vector2f size = sf::Vector2f(70, 70)){
        button.setSize(size);
        button.setFillColor(sf::Color::White);
        button.setPosition(200 + 77*n_x + x, 450 + 77*n_y + y);
        button.setOutlineColor(sf::Color::Black);
        button.setOutlineThickness(2);
    }
    
    /**
     * draw_text creates text in the given rectangle
     * @param s responsible for text
     */
    void draw_text(std::string s){
        font.loadFromFile("Font/Arial.ttf");
        text.setString(s);
        text.setFont(font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Black);
        text.setPosition(button.getPosition().x - text.getGlobalBounds().width/2 + button.getGlobalBounds().width/2, button.getPosition().y + text.getGlobalBounds().height/2 );
    }

};

/**
 * get_from_file gets text from a file and writes by reference to an array
 * @param text - character array
 * @param begin - responsible for the index offset of the cursor in the file
 * @param count - responsible for the number of characters returned
 */
void get_from_file(char *text, int begin = 1, int count = 70){
    std::ifstream in;
    in.open("text.txt");
    in.seekg(begin);
    if (in.is_open()) {
        in.getline(text, count + 1);
    }
    in.close();
}

/**
 * get_random creates a random integer in a given range
 * @param min - responsible for lower limit of number
 * @param max - responsible for upper limit of number
 * @return the value of an integer on a given segment
 */
int get_random(int min, int max)
{
    srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

/**
 * get_text_1 creates correctly typed text
 * @param t - responsible for the text itself
 * @param begin - responsible for the offset of the cursor index in the file
 */
void get_text_1(sf::Text &t, int begin)
{
    char text[120] = "";
    get_from_file(text, begin, 0);
    t.setString(text);
    t.setColor(sf::Color::Green);
}

/**
 * get_text_2 creates the text to be printed
 * @param t2 - responsible for the initial text
 * @param t1 - responsible for correctly typed text
 * @param t_pos - responsible for the position of the text on the screen
 * @param begin - responsible for the offset of the cursor index in the file
 */
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

/**
 * change connects the printed text with the text to be printed
 * @param t1 - responsible for correctly typed text
 * @param t2 - responsible for the initial text
 */
void change(sf::Text &t1, sf::Text &t2){
    std::string s1 = t1.getString();
    std::string s2 = t2.getString();

    s1.push_back(s2[0]);
    s2.erase(0, 1);

    t1.setString(s1);
    t2.setString(s2);
    t2.setPosition(t1.getPosition().x + t1.getGlobalBounds().width + 2, t1.getPosition().y);
}

/**
 * window_hello creates a welcome window
 * @return boolean, open or closed window
 */
bool window_hello() {
    sf::RenderWindow window(sf::VideoMode(500, 300), "Hello");

    sf::Font h1_font;
    h1_font.loadFromFile("Font/Heading.otf");
    sf::Font t_font;
    t_font.loadFromFile("Font/Arial.ttf");

    sf::Text h1("Hello", h1_font, 40);
    h1.setColor(sf::Color::Black);
    h1.setStyle(sf::Text::Bold);
    sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, 20);
    h1.setPosition(centerPos.x - h1.getGlobalBounds().width / 2, centerPos.y);

    sf::Text t(L"This is a keyboard trainer for developing \nfast typing speed in English layout \n\nPress any key to continue", t_font, 25);
    t.setColor(sf::Color::Black);
    t.setPosition(20, h1.getPosition().y + h1.getGlobalBounds().height * 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                window.close();
            }
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
        }

        window.clear(sf::Color::White);
        window.draw(h1);
        window.draw(t);
        window.display();
    }

    return true;
}

/**
 * window_bye creates a summary window
 * @param time - responsible for the typing time of the text
 * @param count - responsible for the count of mistakes
 */
void window_bye(sf::Time time, int count){
    sf::RenderWindow window(sf::VideoMode(500, 300), "Bye");

    sf::Font h1_font;
    h1_font.loadFromFile("Font/Heading.otf");
    sf::Font t_font;
    t_font.loadFromFile("Font/Arial.ttf");

    sf::Text h1("Goodbye", h1_font, 50);
    h1.setColor(sf::Color::Black);
    h1.setStyle(sf::Text::Bold);
    sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, 30);
    h1.setPosition(centerPos.x - h1.getGlobalBounds().width / 2, centerPos.y);

    int sec = time.asSeconds();
    int min = sec / 60;
    int millisec = time.asMilliseconds() % 60;

    sf::Text t;
    t.setOutlineThickness(2);
    t.setOutlineColor(sf::Color::Black);
    std::string timer = "";

    int v = 70 / sec;
    switch (v) {
        case 0:
            timer = "Awful ";
            t.setColor(sf::Color::Black);
            break;
        case 1:
            timer = "Bad ";
            t.setColor(sf::Color::Red);
            break;
        case 2:
            timer = "Normal ";
            t.setColor(sf::Color::Yellow);
            break;
        case 3:
            timer = "Great ";
            t.setColor(sf::Color::Green);
            break;
    }

    sec %= 60;
    timer += std::to_string(min);
    timer += " : ";
    timer += std::to_string(sec);
    timer += " : ";
    timer += std::to_string(millisec);

    sf::Text text("Your time is:", t_font, 30);
    text.setColor(sf::Color::Black);
    text.setPosition(20, h1.getPosition().y + h1.getGlobalBounds().height * 2);

    t.setString(timer);
    t.setFont(t_font);
    t.setCharacterSize(30);
    t.setPosition(40, text.getPosition().y + text.getGlobalBounds().height * 2);

    std::string mistake = "Your number of mistakes is ";
    mistake += std::to_string(count);
    sf::Text text2(mistake, t_font, 30);
    text2.setColor(sf::Color::Black);
    text2.setPosition(20, t.getPosition().y + t.getGlobalBounds().height * 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(h1);
        window.draw(text);
        window.draw(t);
        window.draw(text2);
        window.display();
    }
}
