#define _色空間_

#ifdef _色空間_
#include"libOne.h"
void gmain() {
	window(1920, 1080, 1);
	colorMode(HSV);
	angleMode(RADIANS);
	float hue = 0;
	float satu = 255;
	float value = 255;

	while (notQuit) {
		if (isPress(KEY_F) && hue < 360) hue+= 1;
		if (isTrigger(KEY_D) && hue <= 355) hue += 5;
		if (isPress(KEY_A) && hue > 0) hue+= -1;
		if (isTrigger(KEY_S) && hue >= 5) hue += -5;
		if (isPress(KEY_R) && satu < 255) satu += 1;
		if (isTrigger(KEY_E) && satu <= 250) satu += 5;
		if (isPress(KEY_Q) && satu > 0) satu += -1;
		if (isTrigger(KEY_W) && satu >= 5) satu += -5;
		if (isPress(KEY_V) && value < 255) value += 1;
		if (isTrigger(KEY_C) && value <= 250) value += 5;
		if (isPress(KEY_Z) && value > 0) value += -1;
		if (isTrigger(KEY_X) && value >= 5) value += -5;

		if (isTrigger(KEY_SPACE)) {
			hue = 0;
			satu = 255;
			value = 255;
		}

		clear(0);
		fill(hue, satu, value);
		textSize(120);
		text((let)"hue=" + hue, 600, 400);
		text((let)"satu=" + satu, 600, 600);
		text((let)"value=" + value, 600, 800);

		int num = 1000;
		float angle = hue / num;
		for (int i = 0; i < num; i++) {
			float px = cos(angle*i) * 200;
			float py = -sin(angle*i) * 200;
			strokeWeight(0);
			fill(angle*i, satu, value);
			circle(1500 + px, 540 + py, 50);
		}
	}
}

#endif

#ifdef _ソート_
#include"libOne.h"
void gmain() {
	window(1100,900);
	const int num = 18;
	int score[num];
	int r, c;
	for (int i = 0; i < num; i++) {
		score[i] = random() % 1001;
	}
	while (notQuit) {
		clear(60);

		if (isTrigger(KEY_A)) {
			for (int i = 0; i < num; i++) {
				score[i] = random() % 1001;
			}
		}

		if (isTrigger(KEY_D)) {
			for (r = 0; r < num - 1; r++) {
				for (c = r + 1; c < num; c++) {
					if (score[r] < score[c]) {
						int w = score[r];
						score[r] = score[c];
						score[c] = w;
					}
				}
			}
		}
		
		for (int i = 0; i < num; i++) {
			print(score[i]);
			rect(100, 50 * i, score[i], 40);
		}
	}
}
#endif

#ifdef _射撃_
#include<libOne.h>
void gmain() {
	window(1920, 1080, full);
	clear(74, 84, 89);
	struct PLAYER {
		float px, py, w, h, vx, ofsY;

	};
	struct BULLET {
		float px, py, w, h, vy;
		float hp = 0;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 150;
	p.w = 100;
	p.h = 200;
	p.vx = 10;
	p.ofsY = -150;
	const int numBullets = 30;
	struct BULLET b[numBullets];
	for (int i = 0; i < numBullets; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 10;
		b[i].h = 20;
		b[i].vy = -30;
	}
	while (notQuit) {
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0; i < numBullets; i++) {
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
					i = numBullets;
				}
			}
		}
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				if (b[i].py < b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		clear();
		rectMode(CENTER);
		strokeWeight(0.1);
		for (int i = 0; i < numBullets; i++) {
			if (b[i].hp > 0) {
				rect(b[i].px, b[i].py, b[i].w, b[i].h);
			}
			strokeWeight(3);
			rect(p.px, p.py, p.w, p.h);
		}
	}
}
#endif

#ifdef _一乙(テキスト外枠)_
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	fill(74, 84, 89);

	float ry = -57;
	float v = 5;
	while (notQuit) {
		ry += v;
	    strokeWeight(3);
	    stroke(156, 143, 92);	
	    clear(20);
	    rectMode(CENTER);
	    rect(1920 / 2, ry, 260, 50);
	    if (ry > 540) {
		    v = 0;
	    }
	}
 }

#endif

#ifdef _一乙(テキスト)_
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	fill(74, 84, 89);

	float ty = -10;
	float v = 5;
	while (notQuit) {
		ty += v;
		textSize(40);
		fill(255);
		clear(74, 84, 89);
		text("力尽きました", 820, ty);
		if (ty > 495) {
			v = 0;
		}
	}
}
#endif

#ifdef _一乙_
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	//data
	int hpMax = 1500;
	int hp = hpMax;
	float px = 380;
	float py = 30;
	float h = 12;
	float ry = -27;
	float ty = -10;
	float vr = 25;
	float vt = 25;

	//data update
	while (notQuit) {
		if (hp > 0) {
			if (hp < hpMax) {
				if (isTrigger(KEY_M)) { hp = hpMax; }
			}
			if (hp < 1200) {
				if (isTrigger(KEY_N)) { hp += 300; }
			}
		}
	    clear(74, 84, 89);
		fill(255);

		if (hp > 0) { hp -= 3; }
		strokeWeight(0.1);
		fill(204, 0, 0);
		rect(px, py, hpMax, h);
		fill(74, 227, 66);
		rect(px, py, hp, h);

		if (hp <= 0) {
			clear(74, 84, 89);
			ry += vr;
			strokeWeight(3);
			stroke(156, 143, 92);			
			rectMode(CENTER);
			fill(0);
			rect(1920 / 2, ry, 260, 50);
			if (ry > 540) {
				vr = 0;
			}

			ty += vt;
			textSize(40);
			fill(255);
			text("力尽きました", 840, ty);
			if (ty > 555) {
				vt = 0;
			}
		}

	}
}
#endif

#ifdef _残機_
#include"libOne.h"
void gmain() {
	window(1920, 1080, full);
	//data
	int life = 5;
	float px = 1170;
	float py = 100;
	float radius = 47.5;
	float space = 100;
	while (notQuit) {
		//data update
		if (isTrigger(KEY_D)) { life--; }
		if (isTrigger(KEY_H)) { life++; }

		//drawing
		clear(74, 84, 89);
		fill(200,0,0);
		print((let)"life=" + life);

		//while ver.
		int i = 0;
		while (i < life) {
			float setoffX = space * i;
			strokeWeight(5);
			stroke(200);
			fill(74, 227, 66);
			circle(px + setoffX, py, radius * 2);
			i++;
		}

		//for ver.
		for (int i = 0; i < life; i++) {
			float setoffX = space * i;
			float setoffY = space * 1.2;
			strokeWeight(5);
			stroke(200);
			fill(234, 247, 54);
			circle(px + setoffX, py + setoffY, radius * 2);
		}
	}
}
#endif

#ifdef _振り子？_
#include "libOne.h"
void gmain() {

	window(1920, 1080, full);
	float px = 1920 / 2;
	float py = 1080 / 2;
	float vx = 5;
	float radius = 120;
	float len = rudius / 1.4142 * 2;
	float sw = rudius / 12;
	float angle = 0;
	float angleSpeed = 0.0174532925199;

	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (120 > px || px > 1800) {
			vx = -vx;
			angleSpeed = -angleSpeed;
		}
		clear(31, 30, 51);
		strokeWeight(sw);
		stroke(224, 225, 204);
		circle(px, py, radius * 2);
		fill(61, 58, 125);
		rectMode(CENTER);
		rect(px, py, len, len, angle);
		point(px, py);
		strokeWeight(sw);
		line(1920 / 2, 0, px, py);

	}
	pause();
}
#endif

#ifdef _顔_
#include<libOne.h>
#include<face.h>
void gmain() {
	window(1920, 1080, full);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	int sw1 = 0;
	int sw2 = 0;
	float ofsX = 100;
	float ofsY = 100;
	
	while (notQuit) {
		ofsX = width / 2 - mouseX;
		ofsY = height / 2 - mouseY;
		if (isTrigger(KEY_SPACE)) { sw1 = 1 - sw1; }
		angle += 0.005f;
		if (isTrigger(KEY_ENTER)) { sw2 = 1 - sw2; }
		if (sw2 == 0) { angle = 0; }
		clear(60, 120, 240);
		strokeWeight(5);
		for (int i = -5; i <= 5; i++) {
			if (sw1 == 1) {
				roundFace(px + ofsX * i, py + ofsY * i);
			}
			else {
				squareFace(px + ofsX * i, py + ofsY * i, angle);
			}
		}
	}
}
#endif
