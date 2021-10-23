#ifndef OOP_LAB1_FINAL_CELL_H
#define OOP_LAB1_FINAL_CELL_H

#include <iostream>
#include <memory>

#include "../items/artifact.h"

enum cell_types {
    CELL_NOTHING = 0,
    CELL_ENTRY = 1,
    CELL_EXIT = 2,
};

class cell {

    int _type = 0;
    artifact _item;

    void __copy(const cell& other);
    void __move(cell&& other);

public:

    cell(int type = CELL_NOTHING, const artifact& item = artifact());
    cell(const cell& other);
    cell(cell&& other);

    int type() const;
    void set_type(int type);

    const artifact& item() const;
    void move_item(const artifact& item);

    cell& operator=(const cell& other);
    cell& operator=(cell&& other);

    friend std::ostream& operator<<(std::ostream& out, const cell& c);
};

#endif //OOP_LAB1_FINAL_CELL_H