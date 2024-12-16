#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <SDL2/SDL.h>
#include <unordered_map>
#include <functional>
#include <vector>
#include <iostream>

struct Actions {
    std::function<void()> onPress;
    std::function<void()> onRelease;
};

class Controller {
private:
    SDL_GameController* gameController;
    std::unordered_map<int, Actions> buttonActions;
    std::unordered_map<int, std::function<void(int)>> axisActions;
    std::unordered_map<int, int> currentAxisValues; // Mapa para os valores atuais dos eixos
    std::vector<bool> buttonStates;

public:
    Controller();
    ~Controller();

    void setButtonAction(int button, Actions actions);
    void setAxisAction(int axis, std::function<void(int)> action);
    void processEvent(const SDL_Event& event);
    void listen();
    int getAxisValue(int axis) const; // Novo método para pegar o valor do eixo
};

#endif
