#include "inappproductmodelid.hpp"

using Self = InAppProductModelId;

Self::InAppProductModelId()
    : id_(0) {}

Self::InAppProductModelId(quintptr id)
    : id_(id) {}

Self Self::setRow0(quintptr v) const {
    return setRow0Raw(v + 1);
}

Self Self::setRow1(quintptr v) const {
    return setRow1Raw(v + 1);
}

Self Self::clearRow0() const {
    return setRow0Raw(0);
}

Self Self::clearRow1() const {
    return setRow1Raw(0);
}

int Self::getRow0() const {
    Q_ASSERT(hasRow0());
    return getRow0Raw() - 1;
}

int Self::getRow1() const {
    Q_ASSERT(hasRow1());
    return getRow1Raw() - 1;
}

bool Self::hasRow0() const {
    return getRow0Raw() != 0;
}
bool Self::hasRow1() const {
    return getRow1Raw() != 0;
}

quintptr Self::getId() const {
    return id_;
}

Self Self::setRow0Raw(quintptr v) const {
    Self clone(getId());
    clone.id_ &= ~((1U << row0_bits) - 1);
    clone.id_ |= v;
    return clone;
}

Self Self::setRow1Raw(quintptr v) const {
    Self clone(getId());
    clone.id_ &= ~(((1U << row1_bits) - 1) << row0_bits);
    clone.id_ |= (v << row0_bits);
    return clone;
}

int Self::getRow0Raw() const {
    return id_ & ((1 << row0_bits) - 1);
}

int Self::getRow1Raw() const {
    return (id_ >> row0_bits) & ((1 << row1_bits) - 1);
}
