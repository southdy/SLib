#include "../../../inc/slib/media/camera.h"

SLIB_MEDIA_NAMESPACE_BEGIN

CameraInfo::CameraInfo()
{
}

CameraInfo::~CameraInfo()
{
}


CameraParam::CameraParam()
{
	preferedFrameWidth = 0;
	preferedFrameHeight = 0;
	preferedFrameFormat = BitmapFormat::YUV_NV21;
}

CameraParam::~CameraParam()
{
}

void CameraParam::setFrontCamera()
{
	deviceId = "FRONT";
}

sl_bool CameraParam::isFrontCamera()
{
	return deviceId == "FRONT";
}

void CameraParam::setBackCamera()
{
	deviceId = "BACK";
}

sl_bool CameraParam::isBackCamera()
{
	return deviceId == "BACK";
}


SLIB_DEFINE_OBJECT(Camera, VideoCapture)

Camera::Camera()
{
}

Camera::~Camera()
{
}

SLIB_MEDIA_NAMESPACE_END

