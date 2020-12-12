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

    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * 1000);
}

QuestionColorPlan ZcsColor::get_question_plan()
{
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

    int qid = qrand() % 3;

    return QuestionColorPlan(f, b, w, style_string, qid);
}

AnswerColorPlan ZcsColor::get_answer_plan(QuestionColorPlan *qcp)
{
    string answer_name = qcp->answer_color();
//    qDebug() << answer_name.c_str() << " " << qcp->q_id_;
    size_t sz = v_c_.size();
    int i[3]; //生成3个不同的颜色id
    i[0] = qrand() % sz;
    for(; v_c_[i[0]] == answer_name; i[0] = qrand() % sz);
    i[1] = qrand() % sz;
    for(; i[1] == i[0] || v_c_[i[1]] == answer_name; i[1] = qrand() % sz);
    i[2] = qrand() % sz;
    for(; i[2] == i[1] || i[2] == i[0] || v_c_[i[2]] == answer_name; i[2] = qrand() % sz);

    int aid = qrand() % 4; //答案用哪个按钮
    AnswerColorPlan acp;
    acp.aid_ = aid;
    for(int j = 0, k = 0; j < 4; j ++)
    {
        if(j == aid)
        {
            acp.v_c_.push_back(answer_name);
        }
        else
        {
            acp.v_c_.push_back(v_c_[i[k ++]]);
        }
    }

    for(int j = 0; j < 4; j ++) //40%的概率清空v_c_[j]，说明采用绘制背景色的方式展示按钮
    {
        acp.v_style_.push_back(m_c_[acp.v_c_[j]].b_color());
        int rate = qrand() % 100;
        if(rate >= 60)
        {
            acp.v_c_[j] = "";
        }
    }

    return acp;
}
