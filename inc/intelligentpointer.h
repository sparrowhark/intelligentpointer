/**
 * @file intelligentpointer.h
 * @synopsis:
 * @author sparrowhark
 * @version 1.0
 * @date 2016-10-23
 * Copyright(C) 2016 <stone> All right reserved
 * 
 */
#ifndef INC_INTELLIGENTPOINTER_H_
#define INC_INTELLIGENTPOINTER_H_
#include<stdlib.h>

template<typename T>
class IntelligentPointer {
 private:
    T *m_pt;
    int *m_count;

 private:
    void ReleaseCount() {
        if (m_pt) {
            --(*m_count);
            if (*m_count == 0) {
                delete m_count;
                m_count = NULL;
                delete m_pt;
                m_pt = NULL;
            }
        }
    }

 public:
    explicit IntelligentPointer(T *obj = 0):m_pt(obj), m_count(new int) {
        if (m_pt)
            *m_count = 1;
        else
            *m_count = 0;
    }

    explicit IntelligentPointer(const IntelligentPointer<T> &val) {
        if (this != &val) {
            m_pt = val.m_pt;
            m_count = val.m_count;
            ++(*m_count);
        }
    }

    virtual ~IntelligentPointer() {
        --(*m_count);
        if (*m_count == 0) {
            delete m_count;
            m_count = NULL;
            delete m_pt;
            m_pt = NULL;
        }
    }

    operator bool() {
      return (m_pt == NULL) ? true : false;
    };

    IntelligentPointer& operator=(const IntelligentPointer<T> &val) {
        if (this == &val) {
            return *this;
        }
        ++(*val.m_count);
        ReleaseCount();
        m_pt = val.m_pt;
        m_count = val.m_count;
        return *this;
    }

    T& operator *() {
        if (m_pt != NULL) {
            return *m_pt;
        }
    }

    T* operator ->() {
        if (m_pt != NULL) {
            return m_pt;
        }
    }
};

#endif  // INC_INTELLIGENTPOINTER_H_
