
#define _ 0x000000  //BLACK
#define X 0xFFFFFF  //WHITE
#define Y 0xFFFF00  //YELLOW
#define R 0xFF0000  //RED
#define G 0x08FF00  //GREEN
#define B 0x000FFF  //BLUE
#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 15

int alienBobUp_sprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, _, _, _, R, R, _, R, R, _, _, _, _, _,
    _, _, R, _, R, _, _, _, _, _, R, _, R, _, _,
    _, _, R, _, R, R, R, R, R, R, R, _, R, _, _,
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, _, R, R, _, R, R, R, _, R, R, _, _, _,
    _, _, _, _, R, R, R, R, R, R, R, _, _, _, _,
    _, _, _, _, _, R, _, _, _, R, _, _, _, _, _,
    _, _, _, _, R, _, _, _, _, _, R, _, _, _, _,
};

int alienBobDown_sprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, _, R, _, _, _, _, _, _, _, R, _, _, _,
    _, _, _, _, R, _, _, _, _, _, R, _, _, _, _,
    _, _, _, _, R, R, R, R, R, R, R, _, _, _, _,
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, R, R, R, _, R, R, R, _, R, R, R, _, _,
    _, _, R, _, R, R, R, R, R, R, R, _, R, _, _,
    _, _, R, _, _, R, _, _, _, R, _, _, R, _, _,
    _, _, _, _, R, _, _, _, _, _, R, _, _, _, _,
};

int alienAlice_sprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, _, _, _, _, R, R, R, _, _, _, _, _, _,
    _, _, _, R, R, R, R, R, R, R, R, R, _, _, _,
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, R, R, R, _, _, R, _, _, R, R, R, _, _,
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, _, _, _, R, R, _, R, R, _, _, _, _, _,
    _, _, _, _, R, R, _, _, _, R, R, _, _, _, _,
    _, _, R, R, _, _, _, R, _, _, _, R, R, _, _,
};

int AlienJoe_sprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, _, R, R, R, R, R, R, R, R, R, _, _, _,
    _, _, _, _, R, _, _, R, _, _, R, _, _, _, _,
    _, _, _, _, R, _, _, R, _, _, R, _, _, _, _,
    _, _, _, R, R, R, R, R, R, R, R, R, _, _, _,
    _, _, _, R, _, R, R, R, R, R, _, R, _, _, _,
    _, _, _, R, _, R, R, R, R, R, _, R, _, _, _,
    _, _, _, R, _, R, R, R, R, R, _, R, _, _, _,
};

int AlienMark_sprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, _, _, _, _, R, R, R, _, _, _, _, _, _,
    _, _, _, _, R, R, R, R, R, R, R, _, _, _, _,
    _, _, _, _, R, R, R, R, R, R, R, _, _, _, _,
    _, _, R, R, _, _, _, R, _, _, _, R, R, _, _,
    _, _, R, R, R, R, R, R, R, R, R, R, R, _, _,
    _, _, _, _, R, R, _, R, _, R, R, _, _, _, _,
    _, _, _, _, R, R, _, R, _, R, R, _, _, _, _,
    _, _, R, R, _, _, R, R, R, _, _, R, R, _, _,
};

int ship_sprite[ALIEN_HEIGHT *19] = { 
    _, _, _, _, _, _, _, _, _, G, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, G, G, G, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, G, G, G, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, G, G, G, G, G, _, _, _, _, _, _, _,
    _, _, _, _, _, G, G, G, G, G, G, G, G, G, _, _, _, _, _,
    _, _, _, _, G, G, G, G, G, G, G, G, G, G, G, _, _, _, _,
    _, _, _, _, _, _, _, G, G, _, G, G, _, _, _, _, _, _, _,
    _, _, _, _, _, _, G, G, G, _, G, G, G, _, _, _, _, _, _,
};

int blacksprite[ALIEN_HEIGHT *ALIEN_WIDTH] = { 
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _, _, _, _,
};