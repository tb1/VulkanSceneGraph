#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/core/ref_ptr.h>

#include <vsg/nodes/Node.h>

#include <vector>

namespace vsg
{
    class VSG_EXPORT Group : public vsg::Node
    {
    public:
        Group();

        template<class V> void t_accept(V& visitor) { visitor.apply(*this); }
        template<class V> void t_traverse(V& visitor)
        {
            for (auto child : _children)
            {
                if (child.valid()) child->t_accept(visitor);
            }
        }

        inline virtual void accept(Visitor& visitor) override { Group::t_accept(visitor); }
        inline virtual void traverse(Visitor& visitor) override { Group::t_traverse(visitor); }

        std::size_t addChild(vsg::Node* child) { std::size_t pos = _children.size(); _children.push_back(child); return pos; }

        void removeChild(std::size_t pos) { _children.erase(_children.begin()+pos); }

        vsg::Node* getChild(std::size_t pos) { return _children[pos].get(); }
        const vsg::Node* getChild(std::size_t pos) const { return _children[pos].get(); }

        std::size_t getNumChildren() const { return _children.size(); }

        using Children = std::vector< ref_ptr< vsg::Node> >;

        Children& getChildren() { return _children; }
        const Children& getChildren() const { return _children; }

    protected:

        virtual ~Group();

        Children _children;
    };
}
