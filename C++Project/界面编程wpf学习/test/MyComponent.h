#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace test {

	/// <summary>
	/// MyComponent ժҪ
	/// </summary>
	public ref class MyComponent :  public System::ComponentModel::Component
	{
	public:
		MyComponent(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}
		MyComponent(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Windows.Forms ��׫д�����֧���������
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~MyComponent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			// 
			// button1
			// 
			this->button1->Location = (gcnew System::Drawing::Point(0, 0));
			this->button1->Name = L"button1";
			this->button1->Size = (gcnew System::Drawing::Size(75, 23));
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyComponent::button1_Click);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	};
}
