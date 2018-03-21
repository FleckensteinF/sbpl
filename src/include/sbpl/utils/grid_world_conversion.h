#ifndef _SBPL_GRID_WORLD_CONVERTER_H_
#define _SBPL_GRID_WORLD_CONVERTER_H_

#include <grid_world_conversion/grid_world_conversion.h>
#include <sbpl/utils/utils.h>

class SBPLGridConverter : public GridConverter
{
public:
    using GridConverter::gridToWorld;
    using GridConverter::worldToGrid;

    SBPLGridConverter(int numThetaDirs);
    sbpl_xy_theta_pt_t gridToWorld(const int x, const int y, const int theta) const;
    void worldToGrid(const sbpl_xy_theta_pt_t& pose, int& x_d, int& y_d, int& theta_d) const;
    void contToGrid(const sbpl_xy_theta_pt_t& pose, int& x_d, int& y_d, int& theta_d) const;
    void gridToCont(const int x_d, const int y_d, const int theta_d, sbpl_xy_theta_pt_t& pose) const;
};

#endif // _SBPL_GRID_WORLD_CONVERTER_H_
