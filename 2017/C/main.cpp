#include <iostream>

int main() {
    while (1) {
        int d, w;
        int terrain[10][10];

        int max_water = 0;

        std::cin >> d;
        std::cin >> w;

        //終了判定
        if (d == 0 && w == 0) {
            break;
        }

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                std::cin >> terrain[i][j];
            }
        }
        //x, y座標, 高さ幅の4変数でloop
        for (int y = 0; y < d; y++) {
            for (int x = 0; x < w; x++) {
                for (int height = 3; height <= (d - y); height++) {
                    for (int width = 3; width <= (w - x); width++) {
                        //大きい水量を保持
                        max_water = std::max(max_water, [=]() {
                            int min = 10;
                            int sum = 0;
                            int inside_cell = (height - 2) * (width - 2);
                            int inside_height_max = 0;
                            for (int i = y; i < (y + height); i++) {
                                for (int j = x; j < (x + width); j++) {
                                    if (i == y || i == (y + height - 1) || j == x || j == (x + width - 1)) {
                                        //外側の最小値を求める
                                        min = std::min(min, terrain[i][j]);
                                    } else {
                                        //内側の最大値を求める
                                        inside_height_max = std::max(inside_height_max, terrain[i][j]);
                                        //内側の深さの合計を求める
                                        sum += terrain[i][j];
                                    }
                                }
                            }
                            //内側の最大値が外側の最小値が小さければ水量を返す
                            if (min > inside_height_max) {
                                return min * inside_cell - sum;
                            } else {
                                return 0;
                            }
                        }());
                    }
                }
            }
        }

        std::cout << max_water << std::endl;
    }
    return 0;
}