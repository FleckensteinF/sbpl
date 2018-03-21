#include <grid_world_conversion/grid_world_conversion.h>
#include "sbpl/utils/grid_world_conversion.h"

#include <angles/angles.h>
#include <iostream>
#include <Eigen/Core>

SBPLGridConverter::SBPLGridConverter(int numThetaDirs) :
    GridConverter(numThetaDirs)
{
    
}

sbpl_xy_theta_pt_t SBPLGridConverter::gridToWorld(const int x_d, const int y_d, const int theta_d) const
{
    sbpl_xy_theta_pt_t pose;
    pose.x = discXYToCont(x_d)+mapOffsetX_;
    pose.y = discXYToCont(y_d)+mapOffsetY_;
    pose.theta = discThetaToCont(theta_d);
    return pose;
}

void SBPLGridConverter::worldToGrid(const sbpl_xy_theta_pt_t& pose, int& x_d, int& y_d, int& theta_d) const
{
    x_d = contXYToDisc(pose.x - mapOffsetX_);
    y_d = contXYToDisc(pose.y - mapOffsetY_);
    theta_d = contThetaToDisc(pose.theta);
    //theta_d = NORMALIZEDISCTHETA(theta_d, numThetaDirs_);
    if(theta_d < 0 || theta_d >= numThetaDirs_){
        std::cerr << "ERROR: got discrete theta smaller than 0 or larger than number of valid theta values!" << std::endl;
        exit(1);
    }
}

void SBPLGridConverter::contToGrid(const sbpl_xy_theta_pt_t& pose, int& x_d, int& y_d, int& theta_d) const
{
    x_d = contXYToDisc(pose.x);
    y_d = contXYToDisc(pose.y);
    theta_d = contThetaToDisc(pose.theta);
}

void SBPLGridConverter::gridToCont(const int x_d, const int y_d, const int theta_d, sbpl_xy_theta_pt_t& pose) const
{
    pose.x = discXYToCont(x_d);
    pose.y = discXYToCont(y_d);
    pose.theta = discThetaToCont(theta_d);
}
