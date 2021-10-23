#ifndef OOP_LAB1_FINAL_FIELD_H
#define OOP_LAB1_FINAL_FIELD_H

#include <iostream>

#include "cell.h"
#include "../../utils/containers/matrix/matrix.h"
#include "../../utils/containers/pair/pair.h"

class field {

private:

    matrix<cell> _cells;

    void __copy(const field& other);
    void __move(field&& other);

public:

    using entry_exit_generator = pair<pair<int>,pair<int>> (*)(const field&);

    static pair<pair<int>,pair<int>> default_entry_exit_generator(const field& f);

    field(int width, int height, entry_exit_generator generator = default_entry_exit_generator);
    field(const field& other);
    field(field&& other);

    int width() const;
    int height() const;

    cell& get(int x, int y);
    const cell& get(int x, int y) const;

    field& operator=(const field& other);
    field& operator=(field&& other);

    friend std::ostream& operator<<(std::ostream& out, const field& f);
};

#endif //OOP_LAB1_FINAL_FIELD_H