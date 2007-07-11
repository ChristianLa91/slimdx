/*
* Copyright (c) 2007 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

using namespace System;

#include "Enums.h"

namespace SlimDX
{
	namespace Direct3D10
	{
		ref class EffectMatrixVariable;
		ref class EffectResourceVariable;
		ref class EffectScalarVariable;
		
		public ref class EffectVariable
		{
		protected:
			ID3D10EffectVariable* m_Pointer;
			String^ m_Name;
			String^ m_Semantic;
			EffectVariableFlags m_Flags;
			int m_AnnotationCount;
			int m_BufferOffset;
			int m_ExplicitBindPoint;
			
		internal:
			EffectVariable( ID3D10EffectVariable* variable );
			
		public:
			property String^ Name
			{
				String^ get() { return m_Name; }
			}
			
			property String^ Semantic
			{
				String^ get() { return m_Semantic; }
			}
			
			property EffectVariableFlags Flags
			{
				EffectVariableFlags get() { return m_Flags; }
			}
			
			property int AnnotationCount
			{
				int get() { return m_AnnotationCount; }
			}
			
			property int BufferOffset
			{
				int get() { return m_BufferOffset; }
			}
			
			property int ExplicitBindPoint
			{
				int get() { return m_ExplicitBindPoint; }
			}
			
			property bool IsValid
			{
				bool get() { return m_Pointer->IsValid() ? true : false; }
			}
			
			EffectVariable^ GetAnnotationByIndex( int index );
			EffectVariable^ GetAnnotationByName( String^ name );
			
			EffectVariable^ GetElement( int index );
			
			EffectVariable^ GetMemberByIndex( int index );
			EffectVariable^ GetMemberByName( String^ name );
			EffectVariable^ GetMemberBySemantic( String^ name );
			
			EffectMatrixVariable^ AsMatrix();
			EffectResourceVariable^ AsResource();
			EffectScalarVariable^ AsScalar();
		};
	}
};