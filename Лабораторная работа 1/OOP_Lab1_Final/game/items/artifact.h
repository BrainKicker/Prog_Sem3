#ifndef OOP_LAB1_FINAL_ARTIFACT_H
#define OOP_LAB1_FINAL_ARTIFACT_H

#include <iostream>
#include <memory>

enum artifact_types {
    ART_NOTHING = 0,
};

class artifact {

    class data {
        friend class artifact;

        const int _id = get_id();
        int _type;

    public:
        data(int type);
        data(const data& other);
    };

    std::unique_ptr<data> _data;

    void __copy(const artifact& other);

    void __move(artifact&& other);

    static int get_id();

public:

    artifact();
    artifact(int type);
    artifact(const artifact& other);
    artifact(artifact&& other);

    int type() const;

    int id() const;

    bool is_none() const;

    artifact& operator=(const artifact& other);
    artifact& operator=(artifact&& other);

    friend std::ostream& operator<<(std::ostream& out, const artifact& art);
};

#endif //OOP_LAB1_FINAL_ARTIFACT_H