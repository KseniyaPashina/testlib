#include "SFML/Graphics.hpp"
#include "iostream"
#include "string"
#include "window.cpp"

int main()
{
        sf::RenderWindow window(sf::VideoMode(1500, 900), "Keyboard", sf::Style::None);

        sf::Font h1_font;
        h1_font.loadFromFile("Font/Heading.otf");
        sf::Font t_font;
        t_font.loadFromFile("Font/Arial.ttf");

        sf::Text h1("Keyboard simulator", h1_font, 50);
        h1.setColor(sf::Color::Black);
        h1.setStyle(sf::Text::Bold);
        sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, 50);
        h1.setPosition(centerPos.x - h1.getGlobalBounds().width / 2, centerPos.y);

        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(203, 250)),
                sf::Vertex(sf::Vector2f(1300, 250))
        };
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;

        int number;
        number = get_random(0, 4031);

        sf::Text t1("", t_font, 30);
        t1.setPosition(sf::Vector2f(250, 250));
        get_text_1(t1, number);
        sf::Text t2("", t_font, 30);
        get_text_2(t2, t1, t1.getPosition(), number);

        std::string symbol;
        symbol.reserve(1000);

        sf::Clock clock;
        bool flag = true;

        while (window.isOpen()) {
            sf::Event event;
            std::string s = t2.getString();
            if (flag) clock.restart();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || s.length() == 0) {
                    window.close();
                    sf::Time time = clock.getElapsedTime();
                    window_bye(time);
                } else if (event.type == sf::Event::KeyPressed) {
                    flag = false;
                    const sf::Keyboard::Key keycode = event.key.code;
                    char letter = t2.getString()[0];
                    board[letter].button.setFillColor(sf::Color::Green);
                    if (keycode >= sf::Keyboard::A && keycode <= sf::Keyboard::Z) {
                        char chr = static_cast<char>(keycode - sf::Keyboard::A + 'a');
                        if (chr == letter) {
                            symbol.push_back(chr);
                            board[letter].button.setFillColor(sf::Color::White);
                            change(t1, t2);
                            letter = t2.getString()[0];
                            board[letter].button.setFillColor(sf::Color::Green);
                        }
                    } else if (keycode >= sf::Keyboard::Num0 && keycode <= sf::Keyboard::Num9) {
                        char chr = static_cast<char>(keycode - sf::Keyboard::Num0 + '0');
                        if (chr == letter) {
                            symbol.push_back(chr);
                            board[letter].button.setFillColor(sf::Color::White);
                            change(t1, t2);
                            letter = t2.getString()[0];
                            board[letter].button.setFillColor(sf::Color::Green);
                        }
                    } else if (keycode == sf::Keyboard::Space && ' ' == letter) {
                        symbol.push_back(' ');
                        board[letter].button.setFillColor(sf::Color::White);
                        change(t1, t2);
                        letter = t2.getString()[0];
                        board[letter].button.setFillColor(sf::Color::Green);
                    } else if (keycode == sf::Keyboard::Comma && ',' == letter) {
                        symbol.push_back(',');
                        board[letter].button.setFillColor(sf::Color::White);
                        change(t1, t2);
                        letter = t2.getString()[0];
                        board[letter].button.setFillColor(sf::Color::Green);
                    } else if (keycode == sf::Keyboard::Period && '.' == letter) {
                        symbol.push_back('.');
                        board[letter].button.setFillColor(sf::Color::White);
                        change(t1, t2);
                        letter = t2.getString()[0];
                        board[letter].button.setFillColor(sf::Color::Green);
                    }
                }
            }

            window.clear(sf::Color::White);
            window.draw(h1);

            window.draw(b.button);
            window.draw(b.text);
            window.draw(board['1'].button);
            window.draw(b_1.text);
            window.draw(board['2'].button);
            window.draw(b_2.text);
            window.draw(board['3'].button);
            window.draw(b_3.text);
            window.draw(board['4'].button);
            window.draw(b_4.text);
            window.draw(board['5'].button);
            window.draw(b_5.text);
            window.draw(board['6'].button);
            window.draw(b_6.text);
            window.draw(board['7'].button);
            window.draw(b_7.text);
            window.draw(board['8'].button);
            window.draw(b_8.text);
            window.draw(board['9'].button);
            window.draw(b_9.text);
            window.draw(board['0'].button);
            window.draw(b_0.text);
            window.draw(b_minus.button);
            window.draw(b_minus.text);
            window.draw(b_equal.button);
            window.draw(b_equal.text);
            window.draw(b_backspace.button);
            window.draw(b_backspace.text);

            window.draw(b_tab.button);
            window.draw(b_tab.text);
            window.draw(board['q'].button);
            window.draw(b_q.text);
            window.draw(board['w'].button);
            window.draw(b_w.text);
            window.draw(board['e'].button);
            window.draw(b_e.text);
            window.draw(board['r'].button);
            window.draw(b_r.text);
            window.draw(board['t'].button);
            window.draw(b_t.text);
            window.draw(board['y'].button);
            window.draw(b_y.text);
            window.draw(board['u'].button);
            window.draw(b_u.text);
            window.draw(board['i'].button);
            window.draw(b_i.text);
            window.draw(board['o'].button);
            window.draw(b_o.text);
            window.draw(board['p'].button);
            window.draw(b_p.text);
            window.draw(b_bracket_left.button);
            window.draw(b_bracket_left.text);
            window.draw(b_bracket_right.button);
            window.draw(b_bracket_right.text);
            window.draw(b_slash.button);
            window.draw(b_slash.text);

            window.draw(b_capslock.button);
            window.draw(b_capslock.text);
            window.draw(board['a'].button);
            window.draw(b_a.text);
            window.draw(board['s'].button);
            window.draw(b_s.text);
            window.draw(board['d'].button);
            window.draw(b_d.text);
            window.draw(board['f'].button);
            window.draw(b_f.text);
            window.draw(board['g'].button);
            window.draw(b_g.text);
            window.draw(board['h'].button);
            window.draw(b_h.text);
            window.draw(board['j'].button);
            window.draw(b_j.text);
            window.draw(board['k'].button);
            window.draw(b_k.text);
            window.draw(board['l'].button);
            window.draw(b_l.text);
            window.draw(b_colon.button);
            window.draw(b_colon.text);
            window.draw(b_quotes.button);
            window.draw(b_quotes.text);
            window.draw(b_enter.button);
            window.draw(b_enter.text);

            window.draw(b_shift_1.button);
            window.draw(b_shift_1.text);
            window.draw(board['z'].button);
            window.draw(b_z.text);
            window.draw(board['x'].button);
            window.draw(b_x.text);
            window.draw(board['c'].button);
            window.draw(b_c.text);
            window.draw(board['v'].button);
            window.draw(b_v.text);
            window.draw(board['b'].button);
            window.draw(b_b.text);
            window.draw(board['n'].button);
            window.draw(b_n.text);
            window.draw(board['m'].button);
            window.draw(b_m.text);
            window.draw(board[','].button);
            window.draw(b_comma.text);
            window.draw(board['.'].button);
            window.draw(b_dot.text);
            window.draw(b_question.button);
            window.draw(b_question.text);
            window.draw(b_shift_2.button);
            window.draw(b_shift_2.text);

            window.draw(b_alt_1.button);
            window.draw(b_alt_1.text);
            window.draw(board[' '].button);
            window.draw(b_spacebar.text);
            window.draw(b_alt_2.button);
            window.draw(b_alt_2.text);
            window.draw(b_ctrl.button);
            window.draw(b_ctrl.text);

            window.draw(line, 2, sf::Lines);
            window.draw(t1);
            window.draw(t2);

            sf::Text rez(symbol, t_font, 30);
            rez.setColor(sf::Color::Black);
            rez.setPosition(sf::Vector2f(250, 215));

            window.draw(rez);

            window.display();
        }

    return 0;
}