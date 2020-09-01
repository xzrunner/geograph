#ifndef PARAM_INFO
#error "You must define PARAM_INFO macro before include this file"
#endif

PARAM_INFO(StartPoints, std::vector<sm::vec3>, pts0, m_pts0, ())
PARAM_INFO(EndPoints,   std::vector<sm::vec3>, pts1, m_pts1, ())
