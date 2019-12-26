#pragma once
#define SCREEN_WIDTH  224
#define SCREEN_HEIGHT 256

#include "PlayerBullet.h"
#include "Player.h"
#include "PlayerExplosion.h"
#include "Explosion.h"
#include "Invader.h"
#include "InvaderBullet.h"
#include <stdio.h>
#include "Ground.h"
#include "Pillbox.h"


void setColorWithPosition(vec2 const& position);
extern bool g_keys[256];
extern Player g_player;
extern PlayerExplosion g_playerExplosion;
extern PlayerBullet g_playerBullet;
extern Explosion g_playerBulletExplosion;
extern Explosion g_invaderExplosion;
extern Explosion g_invaderBulletExplosions[INVADER_BULLET_MAX];
extern struct Ground g_ground;