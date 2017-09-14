#include "datastatehelper.hpp"

MonoState::MonoState()
    : index()
    , oldValue()
    , newValue()
    , role() {}

MonoState::MonoState(const QModelIndex& index_, const QVariant& oldValue_,
                     const QVariant& newValue_, int role_)
    : index(index_)
    , oldValue(oldValue_)
    , newValue(newValue_)
    , role(role_) {}

using Self = DataStateHelper;

Self::DataStateHelper()
    : enabled_(true)
    , pushedGroup_(false) {}

void Self::pushGroup() {
    Q_ASSERT(not pushedGroup_);
    pushedGroup_ = true;
    stateGroups_.push(QVector<MonoState>());
}

void Self::popGroup() {
    Q_ASSERT(pushedGroup_);
    pushedGroup_ = false;
    if (stateGroups_.top().empty()) {
        stateGroups_.pop();
    }
}

void Self::setEnabled(bool enabled) {
    enabled_ = enabled;
}

void Self::saveState(const QModelIndex& index, const QVariant& oldValue,
                     const QVariant& newValue, int role) {
    if (not enabled_) {
        return;
    }

    bool shouldPop = false;
    if (not pushedGroup_) {
        pushGroup();
        shouldPop = true;
    }

    undoneStateGroups_.clear();
    stateGroups_.top().push_back(MonoState(index, oldValue, newValue, role));

    if (shouldPop) {
        popGroup();
    }
}

bool Self::canUndo() const {
    return not stateGroups_.empty();
}

bool Self::canRedo() const {
    return not undoneStateGroups_.empty();
}

QVector<MonoState> Self::undo() {
    Q_ASSERT(canUndo());
    auto states = stateGroups_.pop();
    undoneStateGroups_.push(states);
    return states;
}

QVector<MonoState> Self::redo() {
    Q_ASSERT(canRedo());
    auto states = undoneStateGroups_.pop();
    stateGroups_.push(states);
    return states;
}
