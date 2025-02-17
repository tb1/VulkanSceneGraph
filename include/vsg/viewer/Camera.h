#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/state/GraphicsPipeline.h>
#include <vsg/state/ViewportState.h>
#include <vsg/viewer/ProjectionMatrix.h>
#include <vsg/viewer/ViewMatrix.h>

namespace vsg
{
    class VSG_DECLSPEC Camera : public Inherit<Object, Camera>
    {
    public:
        Camera();

        Camera(ref_ptr<ProjectionMatrix> in_projectionMatrix, ref_ptr<ViewMatrix> in_viewMatrix, ref_ptr<ViewportState> in_viewportState = {});

        ref_ptr<ProjectionMatrix> projectionMatrix;
        ref_ptr<ViewMatrix> viewMatrix;
        ref_ptr<ViewportState> viewportState;

        VkViewport getViewport() const { return viewportState ? viewportState->getViewport() : VkViewport{}; }
        VkRect2D getRenderArea() const { return viewportState ? viewportState->getScissor() : VkRect2D{}; }

#if VSG_USE_DEPRECATED_METHODS_AND_IO
        void setProjectionMatrix(ref_ptr<ProjectionMatrix> in_projectionMatrix) { projectionMatrix = in_projectionMatrix; }
        ProjectionMatrix* getProjectionMatrix() const { return projectionMatrix; }

        void setViewMatrix(ref_ptr<ViewMatrix> in_viewMatrix) { viewMatrix = in_viewMatrix; }
        ViewMatrix* getViewMatrix() const { return viewMatrix; }

        void setViewportState(ref_ptr<ViewportState> in_viewportState) { viewportState = in_viewportState; }
        ViewportState* getViewportState() const { return viewportState; }
#endif
    };
    VSG_type_name(vsg::Camera);

} // namespace vsg
