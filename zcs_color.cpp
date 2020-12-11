#include "zcs_color.h"

ZcsColor::ZcsColor()
{
    v_c_.push_back("红");
    v_c_.push_back("绿");
    v_c_.push_back("蓝");
    v_c_.push_back("黄");
    v_c_.push_back("紫");
    v_c_.push_back("青");
    v_c_.push_back("橙");
    v_c_.push_back("黑");

    m_c_.insert(make_pair("红", ColorUnit(255, 000, 000)));
    m_c_.insert(make_pair("绿", ColorUnit(000, 255, 000)));
    m_c_.insert(make_pair("蓝", ColorUnit(000, 000, 255)));
    m_c_.insert(make_pair("黄", ColorUnit(255, 255, 000)));
    m_c_.insert(make_pair("紫", ColorUnit(255, 000, 255)));
    m_c_.insert(make_pair("青", ColorUnit(000, 255, 255)));
    m_c_.insert(make_pair("橙", ColorUnit(250, 128, 010)));
    m_c_.insert(make_pair("黑", ColorUnit(000, 000, 000)));
}

QuestionColorPlan ZcsColor::get_question_plan()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000);
    size_t sz = v_c_.size();
    int i_w = qrand() % sz;
    int i_f = qrand() % sz;
    int i_b = qrand() % sz;
    for(; i_b == i_f; i_b = qrand() % sz);

    string f = v_c_[i_f];
    string b = v_c_[i_b];
    string w = v_c_[i_w];

    string style_string = m_c_[f].f_color() + m_c_[b].b_color();
//    qDebug() << style_string.c_str();

    return QuestionColorPlan(f, b, w, style_string, qrand() % 3);
}
