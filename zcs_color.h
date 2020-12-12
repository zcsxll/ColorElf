#ifndef ZCSCOLOR_H
#define ZCSCOLOR_H

#include <QTime>
#include <QDebug>

#include <vector>
#include <map>
#include <string>

using namespace std;

class ColorUnit
{
public:
    int r_;
    int g_;
    int b_;

    ColorUnit() {qDebug() << "cannot compile without this constructor, no ieda...";}
    ColorUnit(int r, int g, int b)
        :r_(r), g_(g), b_(b) {}

    string f_color()
    {
        string color = "color:rgb(";
        color += to_string(r_) + "," + to_string(g_) + "," + to_string(b_) + ");";
        return color;
    }

    string b_color()
    {
        string color = "background-color:rgb(";
        color += to_string(r_) + "," + to_string(g_) + "," + to_string(b_) + ");";
        return color;
    }
};

class QuestionColorPlan
{
public:
    string f_name_;
    string b_name_;
    string w_name_;
    string style_string_;
    int q_id_; //0->选择前景色，1->选择背景色，2->选择字的含义
    QuestionColorPlan(string f_name, string b_name, string w_name, string style_string, int q_id)
        :f_name_(f_name), b_name_(b_name), w_name_(w_name), style_string_(style_string) ,q_id_(q_id){}

    inline string answer_color()
    {
        return q_id_ == 0 ? f_name_ : (q_id_ == 1 ? b_name_ : w_name_);
    }

    inline string question_audio()
    {
        string audio_file = "assets:/audio_wav/select_";
        audio_file += (q_id_ == 0 ? "f_color" : (q_id_ == 1 ? "b_color" : "w"));
        audio_file += ".wav";
        return audio_file;
    }
};

class AnswerColorPlan
{
public:
    int aid_; //答案id，是下边两个vector的索引
    vector<string> v_c_;
    vector<string> v_style_;

    AnswerColorPlan() {}
};

class ZcsColor
{
private:
    vector<string> v_c_;
    map<string, ColorUnit> m_c_;

public:
    ZcsColor();
    QuestionColorPlan get_question_plan();
    AnswerColorPlan get_answer_plan(QuestionColorPlan *qcp);
};

#endif // ZCSCOLOR_H
