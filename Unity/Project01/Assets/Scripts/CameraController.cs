using UnityEngine;

namespace Project01
{
    public sealed class CameraController : MonoBehaviour
    {
        private Vector3 offset;

        [SerializeField] private GameObject capsule;

        private void Start()
        {
            offset = transform.position - capsule.transform.position;
        }

        private void LateUpdate()
        {
            transform.position = capsule.transform.position + offset;
        }
    }
}
