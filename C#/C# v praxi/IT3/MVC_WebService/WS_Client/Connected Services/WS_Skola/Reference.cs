﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace WS_Client.WS_Skola {
    using System.Runtime.Serialization;
    using System;
    
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Runtime.Serialization", "4.0.0.0")]
    [System.Runtime.Serialization.DataContractAttribute(Name="TridaModel", Namespace="http://tempuri.org/")]
    [System.SerializableAttribute()]
    public partial class TridaModel : object, System.Runtime.Serialization.IExtensibleDataObject, System.ComponentModel.INotifyPropertyChanged {
        
        [System.NonSerializedAttribute()]
        private System.Runtime.Serialization.ExtensionDataObject extensionDataField;
        
        private System.Guid IdField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string NazevField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string TridniField;
        
        private System.DateTime ZmenenoKdyField;
        
        [System.Runtime.Serialization.OptionalFieldAttribute()]
        private string ZmenenoKdoField;
        
        private System.Nullable<int> RocnikField;
        
        private bool UlozenoField;
        
        [global::System.ComponentModel.BrowsableAttribute(false)]
        public System.Runtime.Serialization.ExtensionDataObject ExtensionData {
            get {
                return this.extensionDataField;
            }
            set {
                this.extensionDataField = value;
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(IsRequired=true)]
        public System.Guid Id {
            get {
                return this.IdField;
            }
            set {
                if ((this.IdField.Equals(value) != true)) {
                    this.IdField = value;
                    this.RaisePropertyChanged("Id");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(EmitDefaultValue=false)]
        public string Nazev {
            get {
                return this.NazevField;
            }
            set {
                if ((object.ReferenceEquals(this.NazevField, value) != true)) {
                    this.NazevField = value;
                    this.RaisePropertyChanged("Nazev");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(EmitDefaultValue=false)]
        public string Tridni {
            get {
                return this.TridniField;
            }
            set {
                if ((object.ReferenceEquals(this.TridniField, value) != true)) {
                    this.TridniField = value;
                    this.RaisePropertyChanged("Tridni");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(IsRequired=true)]
        public System.DateTime ZmenenoKdy {
            get {
                return this.ZmenenoKdyField;
            }
            set {
                if ((this.ZmenenoKdyField.Equals(value) != true)) {
                    this.ZmenenoKdyField = value;
                    this.RaisePropertyChanged("ZmenenoKdy");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(EmitDefaultValue=false, Order=4)]
        public string ZmenenoKdo {
            get {
                return this.ZmenenoKdoField;
            }
            set {
                if ((object.ReferenceEquals(this.ZmenenoKdoField, value) != true)) {
                    this.ZmenenoKdoField = value;
                    this.RaisePropertyChanged("ZmenenoKdo");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(IsRequired=true, Order=5)]
        public System.Nullable<int> Rocnik {
            get {
                return this.RocnikField;
            }
            set {
                if ((this.RocnikField.Equals(value) != true)) {
                    this.RocnikField = value;
                    this.RaisePropertyChanged("Rocnik");
                }
            }
        }
        
        [System.Runtime.Serialization.DataMemberAttribute(IsRequired=true, Order=6)]
        public bool Ulozeno {
            get {
                return this.UlozenoField;
            }
            set {
                if ((this.UlozenoField.Equals(value) != true)) {
                    this.UlozenoField = value;
                    this.RaisePropertyChanged("Ulozeno");
                }
            }
        }
        
        public event System.ComponentModel.PropertyChangedEventHandler PropertyChanged;
        
        protected void RaisePropertyChanged(string propertyName) {
            System.ComponentModel.PropertyChangedEventHandler propertyChanged = this.PropertyChanged;
            if ((propertyChanged != null)) {
                propertyChanged(this, new System.ComponentModel.PropertyChangedEventArgs(propertyName));
            }
        }
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="WS_Skola.WS_SkolaSoap")]
    public interface WS_SkolaSoap {
        
        // CODEGEN: Generating message contract since element name HelloWorldResult from namespace http://tempuri.org/ is not marked nillable
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/HelloWorld", ReplyAction="*")]
        WS_Client.WS_Skola.HelloWorldResponse HelloWorld(WS_Client.WS_Skola.HelloWorldRequest request);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/HelloWorld", ReplyAction="*")]
        System.Threading.Tasks.Task<WS_Client.WS_Skola.HelloWorldResponse> HelloWorldAsync(WS_Client.WS_Skola.HelloWorldRequest request);
        
        // CODEGEN: Generating message contract since element name GetTridaModelsResult from namespace http://tempuri.org/ is not marked nillable
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/GetTridaModels", ReplyAction="*")]
        WS_Client.WS_Skola.GetTridaModelsResponse GetTridaModels(WS_Client.WS_Skola.GetTridaModelsRequest request);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/GetTridaModels", ReplyAction="*")]
        System.Threading.Tasks.Task<WS_Client.WS_Skola.GetTridaModelsResponse> GetTridaModelsAsync(WS_Client.WS_Skola.GetTridaModelsRequest request);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/Addition", ReplyAction="*")]
        int Addition(int x, int y);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/Addition", ReplyAction="*")]
        System.Threading.Tasks.Task<int> AdditionAsync(int x, int y);
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.ServiceModel.MessageContractAttribute(IsWrapped=false)]
    public partial class HelloWorldRequest {
        
        [System.ServiceModel.MessageBodyMemberAttribute(Name="HelloWorld", Namespace="http://tempuri.org/", Order=0)]
        public WS_Client.WS_Skola.HelloWorldRequestBody Body;
        
        public HelloWorldRequest() {
        }
        
        public HelloWorldRequest(WS_Client.WS_Skola.HelloWorldRequestBody Body) {
            this.Body = Body;
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.Runtime.Serialization.DataContractAttribute()]
    public partial class HelloWorldRequestBody {
        
        public HelloWorldRequestBody() {
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.ServiceModel.MessageContractAttribute(IsWrapped=false)]
    public partial class HelloWorldResponse {
        
        [System.ServiceModel.MessageBodyMemberAttribute(Name="HelloWorldResponse", Namespace="http://tempuri.org/", Order=0)]
        public WS_Client.WS_Skola.HelloWorldResponseBody Body;
        
        public HelloWorldResponse() {
        }
        
        public HelloWorldResponse(WS_Client.WS_Skola.HelloWorldResponseBody Body) {
            this.Body = Body;
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.Runtime.Serialization.DataContractAttribute(Namespace="http://tempuri.org/")]
    public partial class HelloWorldResponseBody {
        
        [System.Runtime.Serialization.DataMemberAttribute(EmitDefaultValue=false, Order=0)]
        public string HelloWorldResult;
        
        public HelloWorldResponseBody() {
        }
        
        public HelloWorldResponseBody(string HelloWorldResult) {
            this.HelloWorldResult = HelloWorldResult;
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.ServiceModel.MessageContractAttribute(IsWrapped=false)]
    public partial class GetTridaModelsRequest {
        
        [System.ServiceModel.MessageBodyMemberAttribute(Name="GetTridaModels", Namespace="http://tempuri.org/", Order=0)]
        public WS_Client.WS_Skola.GetTridaModelsRequestBody Body;
        
        public GetTridaModelsRequest() {
        }
        
        public GetTridaModelsRequest(WS_Client.WS_Skola.GetTridaModelsRequestBody Body) {
            this.Body = Body;
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.Runtime.Serialization.DataContractAttribute()]
    public partial class GetTridaModelsRequestBody {
        
        public GetTridaModelsRequestBody() {
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.ServiceModel.MessageContractAttribute(IsWrapped=false)]
    public partial class GetTridaModelsResponse {
        
        [System.ServiceModel.MessageBodyMemberAttribute(Name="GetTridaModelsResponse", Namespace="http://tempuri.org/", Order=0)]
        public WS_Client.WS_Skola.GetTridaModelsResponseBody Body;
        
        public GetTridaModelsResponse() {
        }
        
        public GetTridaModelsResponse(WS_Client.WS_Skola.GetTridaModelsResponseBody Body) {
            this.Body = Body;
        }
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
    [System.Runtime.Serialization.DataContractAttribute(Namespace="http://tempuri.org/")]
    public partial class GetTridaModelsResponseBody {
        
        [System.Runtime.Serialization.DataMemberAttribute(EmitDefaultValue=false, Order=0)]
        public WS_Client.WS_Skola.TridaModel[] GetTridaModelsResult;
        
        public GetTridaModelsResponseBody() {
        }
        
        public GetTridaModelsResponseBody(WS_Client.WS_Skola.TridaModel[] GetTridaModelsResult) {
            this.GetTridaModelsResult = GetTridaModelsResult;
        }
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface WS_SkolaSoapChannel : WS_Client.WS_Skola.WS_SkolaSoap, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class WS_SkolaSoapClient : System.ServiceModel.ClientBase<WS_Client.WS_Skola.WS_SkolaSoap>, WS_Client.WS_Skola.WS_SkolaSoap {
        
        public WS_SkolaSoapClient() {
        }
        
        public WS_SkolaSoapClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public WS_SkolaSoapClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public WS_SkolaSoapClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public WS_SkolaSoapClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
        WS_Client.WS_Skola.HelloWorldResponse WS_Client.WS_Skola.WS_SkolaSoap.HelloWorld(WS_Client.WS_Skola.HelloWorldRequest request) {
            return base.Channel.HelloWorld(request);
        }
        
        public string HelloWorld() {
            WS_Client.WS_Skola.HelloWorldRequest inValue = new WS_Client.WS_Skola.HelloWorldRequest();
            inValue.Body = new WS_Client.WS_Skola.HelloWorldRequestBody();
            WS_Client.WS_Skola.HelloWorldResponse retVal = ((WS_Client.WS_Skola.WS_SkolaSoap)(this)).HelloWorld(inValue);
            return retVal.Body.HelloWorldResult;
        }
        
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
        System.Threading.Tasks.Task<WS_Client.WS_Skola.HelloWorldResponse> WS_Client.WS_Skola.WS_SkolaSoap.HelloWorldAsync(WS_Client.WS_Skola.HelloWorldRequest request) {
            return base.Channel.HelloWorldAsync(request);
        }
        
        public System.Threading.Tasks.Task<WS_Client.WS_Skola.HelloWorldResponse> HelloWorldAsync() {
            WS_Client.WS_Skola.HelloWorldRequest inValue = new WS_Client.WS_Skola.HelloWorldRequest();
            inValue.Body = new WS_Client.WS_Skola.HelloWorldRequestBody();
            return ((WS_Client.WS_Skola.WS_SkolaSoap)(this)).HelloWorldAsync(inValue);
        }
        
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
        WS_Client.WS_Skola.GetTridaModelsResponse WS_Client.WS_Skola.WS_SkolaSoap.GetTridaModels(WS_Client.WS_Skola.GetTridaModelsRequest request) {
            return base.Channel.GetTridaModels(request);
        }
        
        public WS_Client.WS_Skola.TridaModel[] GetTridaModels() {
            WS_Client.WS_Skola.GetTridaModelsRequest inValue = new WS_Client.WS_Skola.GetTridaModelsRequest();
            inValue.Body = new WS_Client.WS_Skola.GetTridaModelsRequestBody();
            WS_Client.WS_Skola.GetTridaModelsResponse retVal = ((WS_Client.WS_Skola.WS_SkolaSoap)(this)).GetTridaModels(inValue);
            return retVal.Body.GetTridaModelsResult;
        }
        
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Advanced)]
        System.Threading.Tasks.Task<WS_Client.WS_Skola.GetTridaModelsResponse> WS_Client.WS_Skola.WS_SkolaSoap.GetTridaModelsAsync(WS_Client.WS_Skola.GetTridaModelsRequest request) {
            return base.Channel.GetTridaModelsAsync(request);
        }
        
        public System.Threading.Tasks.Task<WS_Client.WS_Skola.GetTridaModelsResponse> GetTridaModelsAsync() {
            WS_Client.WS_Skola.GetTridaModelsRequest inValue = new WS_Client.WS_Skola.GetTridaModelsRequest();
            inValue.Body = new WS_Client.WS_Skola.GetTridaModelsRequestBody();
            return ((WS_Client.WS_Skola.WS_SkolaSoap)(this)).GetTridaModelsAsync(inValue);
        }
        
        public int Addition(int x, int y) {
            return base.Channel.Addition(x, y);
        }
        
        public System.Threading.Tasks.Task<int> AdditionAsync(int x, int y) {
            return base.Channel.AdditionAsync(x, y);
        }
    }
}
