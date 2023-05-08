#pragma

#include "Location.h"
#include "EnemyBlob.h"

class Model {
public:
    ~Model() {
        for (auto enemy : enemies) {
            delete enemy;
        }
    }
private:
    Location *location;
    QPoint position;
    std::vector<Enemy *> enemies = std::vector<Enemy *>({new EnemyBlob(QPoint(0, 0))});
};
