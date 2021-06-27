#include "iostream"
#include "string"
#include "window.cpp"

int main()
{
    // was the welcome window closed
    if (window_hello()) {
        
        // creating the screen
        sf::RenderWindow window(sf::VideoMode(1500, 900), "Keyboard", sf::Style::None);
        
        // creating font
        sf::Font h1_font;
        h1_font.loadFromFile("Font/Heading.otf");
        sf::Font t_font;
        t_font.loadFromFile("Font/Arial.ttf");
        
        // creating text on the screen
        sf::Text h1("Keyboard simulator", h1_font, 50);
        h1.setColor(sf::Color::Black);
        h1.setStyle(sf::Text::Bold);
        sf::Vector2f centerPos = sf::Vector2f(window.getSize().x / 2, 50);
        h1.setPosition(centerPos.x - h1.getGlobalBounds().width / 2, centerPos.y);

        // creating main line
        sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(203, 250)),
                sf::Vertex(sf::Vector2f(1300, 250))
        };
        line[0].color = sf::Color::Black;
        line[1].color = sf::Color::Black;

        // creating a random number
        int number;
        number = get_random(0, 4031);

        // creating the text that was printed and needs to be printed
        sf::Text t1("", t_font, 30);
        t1.setPosition(sf::Vector2f(250, 250));
        get_text_1(t1, number);
        sf::Text t2("", t_font, 30);
        get_text_2(t2, t1, t1.getPosition(), number);

        // creating printable text
        std::string symbol;
        symbol.reserve(1000);

        // creating a dictionary of keyboard buttons
        std::map<char, Keyboard> board;

        Keyboard b;
        b.set_value();
        b.draw_button();
        b.draw_text("!");
        board.insert(std::pair<char, Keyboard>('!', b));

        Keyboard b_1;
        b_1.set_value(1, 0);
        b_1.draw_button();
        b_1.draw_text("1");
        board.insert(std::pair<char, Keyboard>('1', b_1));

        Keyboard b_2;
        b_2.set_value(2, 0);
        b_2.draw_button();
        b_2.draw_text("2");
        board.insert(std::pair<char, Keyboard>('2', b_2));

        Keyboard b_3;
        b_3.set_value(3, 0);
        b_3.draw_button();
        b_3.draw_text("3");
        board.insert(std::pair<char, Keyboard>('3', b_3));

        Keyboard b_4;
        b_4.set_value(4, 0);
        b_4.draw_button();
        b_4.draw_text("4");
        board.insert(std::pair<char, Keyboard>('4', b_4));

        Keyboard b_5;
        b_5.set_value(5, 0);
        b_5.draw_button();
        b_5.draw_text("5");
        board.insert(std::pair<char, Keyboard>('5', b_5));

        Keyboard b_6;
        b_6.set_value(6, 0);
        b_6.draw_button();
        b_6.draw_text("6");
        board.insert(std::pair<char, Keyboard>('6', b_6));

        Keyboard b_7;
        b_7.set_value(7, 0);
        b_7.draw_button();
        b_7.draw_text("7");
        board.insert(std::pair<char, Keyboard>('7', b_7));

        Keyboard b_8;
        b_8.set_value(8, 0);
        b_8.draw_button();
        b_8.draw_text("8");
        board.insert(std::pair<char, Keyboard>('8', b_8));

        Keyboard b_9;
        b_9.set_value(9, 0);
        b_9.draw_button();
        b_9.draw_text("9");
        board.insert(std::pair<char, Keyboard>('9', b_9));

        Keyboard b_0;
        b_0.set_value(10, 0);
        b_0.draw_button();
        b_0.draw_text("0");
        board.insert(std::pair<char, Keyboard>('0', b_0));

        Keyboard b_minus;
        b_minus.set_value(11, 0);
        b_minus.draw_button();
        b_minus.draw_text("-");

        Keyboard b_equal;
        b_equal.set_value(12, 0);
        b_equal.draw_button();
        b_equal.draw_text("=");

        Keyboard b_backspace;
        b_backspace.set_value(13, 0);
        b_backspace.draw_button(sf::Vector2f(105, 70));
        b_backspace.draw_text("BS");

        Keyboard b_tab;
        b_tab.set_value(0, 1);
        b_tab.draw_button(sf::Vector2f(105, 70));
        b_tab.draw_text("Tab");

        Keyboard b_q;
        b_q.set_value(1, 1, 35);
        b_q.draw_button();
        b_q.draw_text("Q");
        board.insert(std::pair<char, Keyboard>('q', b_q));

        Keyboard b_w;
        b_w.set_value(2, 1, 35);
        b_w.draw_button();
        b_w.draw_text("W");
        board.insert(std::pair<char, Keyboard>('w', b_w));

        Keyboard b_e;
        b_e.set_value(3, 1, 35);
        b_e.draw_button();
        b_e.draw_text("E");
        board.insert(std::pair<char, Keyboard>('e', b_e));

        Keyboard b_r;
        b_r.set_value(4, 1, 35);
        b_r.draw_button();
        b_r.draw_text("R");
        board.insert(std::pair<char, Keyboard>('r', b_r));

        Keyboard b_t;
        b_t.set_value(5, 1, 35);
        b_t.draw_button();
        b_t.draw_text("T");
        board.insert(std::pair<char, Keyboard>('t', b_t));

        Keyboard b_y;
        b_y.set_value(6, 1, 35);
        b_y.draw_button();
        b_y.draw_text("Y");
        board.insert(std::pair<char, Keyboard>('y', b_y));

        Keyboard b_u;
        b_u.set_value(7, 1, 35);
        b_u.draw_button();
        b_u.draw_text("U");
        board.insert(std::pair<char, Keyboard>('u', b_u));

        Keyboard b_i;
        b_i.set_value(8, 1, 35);
        b_i.draw_button();
        b_i.draw_text("I");
        board.insert(std::pair<char, Keyboard>('i', b_i));

        Keyboard b_o;
        b_o.set_value(9, 1, 35);
        b_o.draw_button();
        b_o.draw_text("O");
        board.insert(std::pair<char, Keyboard>('o', b_o));

        Keyboard b_p;
        b_p.set_value(10, 1, 35);
        b_p.draw_button();
        b_p.draw_text("P");
        board.insert(std::pair<char, Keyboard>('p', b_p));

        Keyboard b_bracket_left;
        b_bracket_left.set_value(11, 1, 35);
        b_bracket_left.draw_button();
        b_bracket_left.draw_text("[");

        Keyboard b_bracket_right;
        b_bracket_right.set_value(12, 1, 35);
        b_bracket_right.draw_button();
        b_bracket_right.draw_text("]");

        Keyboard b_slash;
        b_slash.set_value(13, 1, 35);
        b_slash.draw_button();
        b_slash.draw_text("\\");

        Keyboard b_capslock;
        b_capslock.set_value(0, 2);
        b_capslock.draw_button(sf::Vector2f(128, 70));
        b_capslock.draw_text("CLock");

        Keyboard b_a;
        b_a.set_value(1, 2, 58);
        b_a.draw_button();
        b_a.draw_text("A");
        board.insert(std::pair<char, Keyboard>('a', b_a));

        Keyboard b_s;
        b_s.set_value(2, 2, 58);
        b_s.draw_button();
        b_s.draw_text("S");
        board.insert(std::pair<char, Keyboard>('s', b_s));

        Keyboard b_d;
        b_d.set_value(3, 2, 58);
        b_d.draw_button();
        b_d.draw_text("D");
        board.insert(std::pair<char, Keyboard>('d', b_d));

        Keyboard b_f;
        b_f.set_value(4, 2, 58);
        b_f.draw_button();
        b_f.draw_text("F");
        board.insert(std::pair<char, Keyboard>('f', b_f));

        Keyboard b_g;
        b_g.set_value(5, 2, 58);
        b_g.draw_button();
        b_g.draw_text("G");
        board.insert(std::pair<char, Keyboard>('g', b_g));

        Keyboard b_h;
        b_h.set_value(6, 2, 58);
        b_h.draw_button();
        b_h.draw_text("H");
        board.insert(std::pair<char, Keyboard>('h', b_h));

        Keyboard b_j;
        b_j.set_value(7, 2, 58);
        b_j.draw_button();
        b_j.draw_text("J");
        board.insert(std::pair<char, Keyboard>('j', b_j));

        Keyboard b_k;
        b_k.set_value(8, 2, 58);
        b_k.draw_button();
        b_k.draw_text("K");
        board.insert(std::pair<char, Keyboard>('k', b_k));

        Keyboard b_l;
        b_l.set_value(9, 2, 58);
        b_l.draw_button();
        b_l.draw_text("L");
        board.insert(std::pair<char, Keyboard>('l', b_l));

        Keyboard b_colon;
        b_colon.set_value(10, 2, 58);
        b_colon.draw_button();
        b_colon.draw_text(":");

        Keyboard b_quotes;
        b_quotes.set_value(11, 2, 58);
        b_quotes.draw_button();
        b_quotes.draw_text(" \" \" ");

        Keyboard b_enter;
        b_enter.set_value(12, 2, 58);
        b_enter.draw_button(sf::Vector2f(124, 70));
        b_enter.draw_text("Enter");

        Keyboard b_shift_1;
        b_shift_1.set_value(0, 3);
        b_shift_1.draw_button(sf::Vector2f(165, 70));
        b_shift_1.draw_text("Shift");

        Keyboard b_z;
        b_z.set_value(1, 3, 95);
        b_z.draw_button();
        b_z.draw_text("Z");
        board.insert(std::pair<char, Keyboard>('z', b_z));

        Keyboard b_x;
        b_x.set_value(2, 3, 95);
        b_x.draw_button();
        b_x.draw_text("X");
        board.insert(std::pair<char, Keyboard>('x', b_x));

        Keyboard b_c;
        b_c.set_value(3, 3, 95);
        b_c.draw_button();
        b_c.draw_text("C");
        board.insert(std::pair<char, Keyboard>('c', b_c));

        Keyboard b_v;
        b_v.set_value(4, 3, 95);
        b_v.draw_button();
        b_v.draw_text("V");
        board.insert(std::pair<char, Keyboard>('v', b_v));

        Keyboard b_b;
        b_b.set_value(5, 3, 95);
        b_b.draw_button();
        b_b.draw_text("B");
        board.insert(std::pair<char, Keyboard>('b', b_b));

        Keyboard b_n;
        b_n.set_value(6, 3, 95);
        b_n.draw_button();
        b_n.draw_text("N");
        board.insert(std::pair<char, Keyboard>('n', b_n));

        Keyboard b_m;
        b_m.set_value(7, 3, 95);
        b_m.draw_button();
        b_m.draw_text("M");
        board.insert(std::pair<char, Keyboard>('m', b_m));

        Keyboard b_comma;
        b_comma.set_value(8, 3, 95);
        b_comma.draw_button();
        b_comma.draw_text(",");
        board.insert(std::pair<char, Keyboard>(',', b_comma));

        Keyboard b_dot;
        b_dot.set_value(9, 3, 95);
        b_dot.draw_button();
        b_dot.draw_text(".");
        board.insert(std::pair<char, Keyboard>('.', b_dot));

        Keyboard b_question;
        b_question.set_value(10, 3, 95);
        b_question.draw_button();
        b_question.draw_text(" / ?");

        Keyboard b_shift_2;
        b_shift_2.set_value(11, 3, 95);
        b_shift_2.draw_button(sf::Vector2f(165, 70));
        b_shift_2.draw_text("Shift");

        Keyboard b_alt_1;
        b_alt_1.set_value(2, 4, 95);
        b_alt_1.draw_button();
        b_alt_1.draw_text("Alt");

        Keyboard b_spacebar;
        b_spacebar.set_value(3, 4, 95);
        b_spacebar.draw_button(sf::Vector2f(378, 70));
        b_spacebar.draw_text("");
        board.insert(std::pair<char, Keyboard>(' ', b_spacebar));

        Keyboard b_alt_2;
        b_alt_2.set_value(4, 4, 403);
        b_alt_2.draw_button();
        b_alt_2.draw_text("Alt");

        Keyboard b_ctrl;
        b_ctrl.set_value(5, 4, 403);
        b_ctrl.draw_button();
        b_ctrl.draw_text("Ctrl");

        // creating timer
        sf::Clock clock;
        bool flag = true;
        
        // cout of mistackes
        int count = 0;

        while (window.isOpen()) {
            sf::Event event;
            std::string s = t2.getString();
            if (flag) clock.restart();
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || s.length() == 0) {
                    window.close();
                    sf::Time time = clock.getElapsedTime();
                    window_bye(time, count);
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
                        } else count += 1;
                    } else if (keycode >= sf::Keyboard::Num0 && keycode <= sf::Keyboard::Num9) {
                        char chr = static_cast<char>(keycode - sf::Keyboard::Num0 + '0');
                        if (chr == letter) {
                            symbol.push_back(chr);
                            board[letter].button.setFillColor(sf::Color::White);
                            change(t1, t2);
                            letter = t2.getString()[0];
                            board[letter].button.setFillColor(sf::Color::Green);
                        } else count += 1;
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
    }
    return 0;
}
