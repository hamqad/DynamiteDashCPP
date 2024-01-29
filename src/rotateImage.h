//#pragma once
//#include "ImagePixelMapping.h"
//class rotateImage :
//    public ImagePixelMapping
//{
//public:
//	rotateImage(double r)
//		: rotation(r)
//	{
//	}
//
//	virtual bool mapCoordinates(double& x, double& y, const SimpleImage& image) override
//	{
//		if (x < 0) return false;
//		if (y < 0) return false;
//		if (x >= (image.getWidth() - 0.5)) return false;
//		if (y >= (image.getHeight() - 0.5)) return false;
//
//		// Shift offset to the centre of the image, so we can rotate around centre
//		x -= image.getWidth() / 2;
//		y -= image.getHeight() / 2;
//
//		// Rotate it
//		double dAngle = atan(y / (x + 0.0001));
//		if (x < 0)
//			dAngle += M_PI;
//		double hyp = ::sqrt(x * x + y * y);
//		dAngle += (double)rotation;
//
//		x = hyp * ::cos(dAngle);
//		y = hyp * ::sin(dAngle);
//
//		// Shift offset back to the corner
//		x += image.getWidth() / 2;
//		y += image.getHeight() / 2;
//
//		if (x < 0) return false;
//		if (y < 0) return false;
//		if (x >= (image.getWidth() - 0.5)) return false;
//		if (y >= (image.getHeight() - 0.5)) return false;
//
//		return true;
//	}
//
//	double getRotation() { return rotation; }
//	void setRotation(double r) { rotation = r; }
//
//protected:
//	double rotation;
//};
//
