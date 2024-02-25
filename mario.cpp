#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>


using namespace sf ;
int main()
{
    RenderWindow window(VideoMode(600, 600), "SFML works!");

sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(280, 50)),
    sf::Vertex(sf::Vector2f(420, 50))

};

sf::Font font;
 if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold );
    text.setPosition({280, 0});
    text.setString("TOP TEN");

    CircleShape circle(100);
    circle.setFillColor(Color{ 0x006495FF });
    circle.setOutlineColor(Color{ 255, 255, 255, 255 });
    circle.setOutlineThickness(5);
    circle.setPosition({ 390, 390 });

    RectangleShape rectangle{ { 220, 160 } };
    rectangle.setFillColor(Color::Black);
    rectangle.setPosition({ 230, 100 });
    rectangle.rotate(0);





    Texture texture;
    texture.loadFromFile("pngegg.png");
    Sprite mario1;
    mario1.setTexture(texture);
    mario1.scale(sf::Vector2f(.2,.2));
    mario1.setPosition(sf::Vector2f(0,0));

    Texture texture2;
    texture2.loadFromFile("1.png");
    Sprite mario2;
    mario2.setTexture(texture2);
    mario2.setPosition(sf::Vector2f(400,400));
    mario2.scale(sf::Vector2f(.5,.5));

    sf::SoundBuffer buffer;

    if (!buffer.loadFromFile("n.wav"))
        {
           return -1;
        }
        sf::Sound sound;

        sound.setBuffer(buffer);








    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

         if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Up)
                mario1.move(0,-1);

            else if (event.key.code == Keyboard::Down)
            mario1.move(0,1);

            else if (event.key.code == Keyboard::Left)
            mario1.move(-1,0);

           else if (event.key.code == Keyboard::Right)
            mario1.move(1,0);
         }

         if(mario1.getGlobalBounds().intersects(mario2.getGlobalBounds()))
         {
            sound.play();
         }

        window.clear();
        window.draw(line, 2, sf::Lines);
        window.draw(mario1);
        window.draw(mario2);

        window.draw(text);

        window.display();
    }




    return 0;
}
