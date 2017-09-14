#ifndef INAPPPRODUCTMODELID_HPP
#define INAPPPRODUCTMODELID_HPP

#include <QtGlobal>

class InAppProductModelId {
private:
    using Self = InAppProductModelId;

    static constexpr int row0_bits = 8;
    static constexpr int row1_bits = 8;

public:
    InAppProductModelId();

    explicit InAppProductModelId(quintptr id);

    Self setRow0(quintptr v) const;
    Self setRow1(quintptr v) const;

    Self clearRow0() const;
    Self clearRow1() const;

    int getRow0() const;
    int getRow1() const;

    bool hasRow0() const;
    bool hasRow1() const;

    quintptr getId() const;

protected:
    Self setRow0Raw(quintptr v) const;
    Self setRow1Raw(quintptr v) const;

    int getRow0Raw() const;
    int getRow1Raw() const;

private:
    quintptr id_;
};

#endif // INAPPPRODUCTMODELID_HPP
