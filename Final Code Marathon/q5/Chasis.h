#ifndef CHASIS_H
#define CHASIS_H

#include<iostream>
#include"ChasisMaterial.h"
#include"ChasisType.h"

class Chasis
{
private:
    ChasisType m_chasis_type;
    float m_chasis_width;
    float m_chasis_length;
    bool m_is_chasis_platform_ev_compatible;
    bool m_is_chasis_ncap_compliant;
    ChasisMaterial m_chasis_material;
public:
    Chasis() = default;
    ~Chasis() = default;

    Chasis(const Chasis&) = default;
    Chasis(Chasis&&) = default;

    Chasis& operator=(const Chasis&) = default;
    Chasis& operator=(Chasis&&) = default;

    Chasis(ChasisType ctype , float wid , float len,bool ev , bool ncap ,ChasisMaterial mat );

    ChasisType chasisType() const { return m_chasis_type; }
    void setChasisType(const ChasisType &chasis_type) { m_chasis_type = chasis_type; }

    float chasisWidth() const { return m_chasis_width; }
    void setChasisWidth(float chasis_width) { m_chasis_width = chasis_width; }

    float chasisLength() const { return m_chasis_length; }
    void setChasisLength(float chasis_length) { m_chasis_length = chasis_length; }

    bool isChasisPlatformEvCompatible() const { return m_is_chasis_platform_ev_compatible; }
    void setIsChasisPlatformEvCompatible(bool is_chasis_platform_ev_compatible) { m_is_chasis_platform_ev_compatible = is_chasis_platform_ev_compatible; }

    bool isChasisNcapCompliant() const { return m_is_chasis_ncap_compliant; }
    void setIsChasisNcapCompliant(bool is_chasis_ncap_compliant) { m_is_chasis_ncap_compliant = is_chasis_ncap_compliant; }

    ChasisMaterial chasisMaterial() const { return m_chasis_material; }
    void setChasisMaterial(const ChasisMaterial &chasis_material) { m_chasis_material = chasis_material; }

    friend std::ostream &operator<<(std::ostream &os, const Chasis &rhs);
};

#endif // CHASIS_H
