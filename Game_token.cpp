#include "Game_token_base.h"
#include "Game_token.h"

namespace Grid_game {
    // make function
    void Token::move(direction move){
    //holds the old positions to return to
        int orginX = x;
        int orginY = y;
    //NOTE: so the variables above are a way to get back to the previous position. It is your choice on what you want to do.
    //I am just giving examples for you guys to change up your codes and what not


    //  up
    if (move == 0){
        // since y is opposite we check the up direction if it compares to zero because that determines if it is out of bounds or not
        if (y == 0){
        // do not change poisiton
        return;
        }
        else {
            // increment y value
            y -= 1;
            // check if space is a barrier
            if (board.retrieve_space(x, y).type() == 1){
            y = orginY;
            // go back to orginal space
            y += 1;
            }
        }
    }

    // right
    if (move == 1){
        // right is going to the edge of the board so we check the width - 1 since we are starting from zero (werid comp sci rules)
        if (x == board.width() - 1){
        // do not change current position
        return;
        }
        else {
            // increment x value to next poistion
            x += 1;
            // check if space moved to is a barrier
            if (board.retrieve_space(x, y).type() == 1) {
            // go back to original space
            x -= 1;
            x = orginX;
            }
        }
    }
    
    // down
    if (move == 2) {
        // check if y is out of bounds y > height
        if (y == board.height()){
        // stay at current position
            return;
        }
        else {
            // increment to next position
            y += 1;

            // check barrier
            if (board.retrieve_space(x, y).type() == 1){
            // decrement to next position
            y -= 1;
            y = orginY;
            }
        }
    }

    // left
    if (move == 3){
        // check out of bounds
        if (x == 0){
        // do not change position
        return;
        }

        else {
            // decrement next position
            x -= 1;
            // chcek if space is a barrier
            if (board.retrieve_space(x, y).type() == 1){
                x = orginX;
                // move back to old position
                x += 1;
            }
        }
    }
}

void Token::move_special(vector<direction> vecMove){
    move(vecMove[0]);
    // return;
}

void Token::apply_terrain_effect(Space::terrain_type terrain){
    // empty
    if (terrain == 0){
        return;
    }
    // water
    if (terrain == 2){
        hp -= 1;
        pp -= 1;
    }
    // lava
    if (terrain == 3){
        hp = 0;
        pp = 0;
    }
  }
}